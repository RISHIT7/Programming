from flask import Flask
from Flask10_second import second

app = Flask(__name__)
app.register_blueprint(second, url_prefix="/admin")

@app.route("/")
def test():
    return "<h1>Test</h1> for more info checkout exploreflask webpage "

if __name__ == "__main__":
    app.run()