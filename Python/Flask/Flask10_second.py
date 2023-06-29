from flask import Blueprint, render_template

second = Blueprint("second", __name__, static_folder="static",
                   template_folder="Templates")

@second.route("/home")
@second.route("/")
def home():
    return render_template("Flask9_base.html")