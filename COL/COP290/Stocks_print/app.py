from flask import Flask, render_template
import plotly.graph_objs as go
from jugaad_data.nse import stock_df
from datetime import date
from dateutil.relativedelta import relativedelta
app = Flask(__name__)

today = date.today()
last = today - relativedelta(years=2)

df = stock_df(symbol="SBIN", from_date=last, to_date=today, series="EQ")

@app.route('/')
def index():
    candlestick_chart = generate_candlestick_chart()
    return render_template('index.html', candlestick_chart=candlestick_chart)

def generate_candlestick_chart():
    candlestick_trace = go.Candlestick(x=df['DATE'],
                                       open=df['OPEN'],
                                       high=df['HIGH'],
                                       low=df['LOW'],
                                       close=df['CLOSE'])

    layout = go.Layout(title='Candlestick Chart', xaxis=dict(title='Date'), yaxis=dict(title='Price'),height=800, xaxis_rangeslider_visible=False,dragmode='pan')

    figure = go.Figure(data=[candlestick_trace], layout=layout)
    return figure.to_html(full_html=False)

if __name__ == '__main__':
    app.run(debug=True)

