from optparse import Values
from flask import Flask, redirect, url_for, render_template, request, session, flash
from datetime import timedelta
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)
app.secret_key = "hello"
app.config["SQLALCHEMY_DATABASE_URI"] = "sqlite:///ssusers.sqlite3"
app.config["SQLALCHEMY_TRACK_MODIFICATIONS"] = False
# stores session data for 5 days, or it'll be deleted when the browser closes
app.permanent_session_lifetime = timedelta(days=5)

db = SQLAlchemy(app)

class users(db.Model):
    _id = db.Column("id", db.Integer, primary_key=True)
    name = db.Column(db.String(100))
    email = db.Column(db.String(100))

    def __init__(self, name, email):
        self.name = name
        self.email = email


@app.route("/")
def home():
    return render_template("Flask7.html")

@app.route("/view")
def view():
    return render_template("Flask7_view.html", values=users.query.all())

@app.route("/login", methods=["POST", "GET"])
def login():
    if request.method == "POST":
        session.permanent = True  # thus this session last forever
        user = request.form["nm"]
        session["user"] = user
        found_user = users.query.filter_by(name=user).first()
        """
        to delete an object, 
        found_user = users.query.filter_by(name=user).delete()
        for user in found_user:
            user.delete()
            then commit
        """
        if found_user :
            session["email"] = found_user.email()

        else:
            usr = users(user, "")
            db.session.add(usr)
            db.session.commit()
        
        flash("Login Succesful!")
        return redirect(url_for("user"))
    else:
        if "user" in session:
            flash("Already Logged in!")
            return redirect(url_for("user"))

        return render_template("Flask7_login.html")


@app.route("/user", methods=["POST", "GET"])
def user():
    email = None
    if "user" in session:
        user = session["user"]
        if request.method == "POST":
            email = request.form["email"]
            session["email"] = email
            found_user = users.query.filter_by(name=user).first()
            found_user.email = email
            db.session.commit()
            flash("Email was saved!")
        else :
            if "email" in session:
                email = session["email"]
        return render_template("Flask7_user.html", email=email)
    else:
        flash("You are not logged in!")
        return redirect(url_for("login"))


@app.route("/logout")
def logout():
    if "user" in session:
        user = session["user"]
        flash(f"You have been Logged Out!, {user}", "info")
    session.pop("user", None)
    session.pop("email", None)
    return redirect(url_for("home"))


if __name__ == "__main__":
    db.create_all()
    app.run()
