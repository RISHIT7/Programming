from flask import Flask, redirect, url_for, render_template, request, session, flash
from datetime import timedelta

app = Flask(__name__)
app.secret_key = "hello"
# stores session data for 5 days, or it'll be deleted when the browser closes
app.permanent_session_lifetime = timedelta(days=5)


@app.route("/")
def home():
    return render_template("Flask6.html")


@app.route("/login", methods=["POST", "GET"])
def login():
    if request.method == "POST":
        session.permanent = True  # thus this session last forever
        user = request.form["nm"]
        session["user"] = user
        flash("Login Succesful!")
        return redirect(url_for("user"))
    else:
        if "user" in session:
            flash("Already Logged in!")
            return redirect(url_for("user"))

        return render_template("Flask6_login.html")


@app.route("/user")
def user():
    if "user" in session:
        user = session["user"]
        return render_template("Flask6_user.html", user=user)
    else:
        flash("You are not logged in!")
        return redirect(url_for("login"))


@app.route("/logout")
def logout():
    if "user" in session:
        user = session["user"]
        flash(f"You have been Logged Out!, {user}", "info")
    session.pop("user", None)
    return redirect(url_for("home"))


if __name__ == "__main__":
    app.run()
