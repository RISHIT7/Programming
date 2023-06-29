from flask import Flask, render_template, url_for, redirect, session, request

app = Flask(__name__)

@app.route("/home")
@app.route("/")
def home():
    return render_template("Flask9_base.html")


if __name__ == "__main__":
    app.run()