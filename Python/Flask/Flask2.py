from flask import Flask, redirect, url_for, render_template

app = Flask(__name__)

@app.route("/<name>")
def home(name):
    return render_template("Flask2.html", content=["tim", "jo", "biil"])

if __name__ == "__main__":
    app.run()