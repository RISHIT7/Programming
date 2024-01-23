from flask import Blueprint, render_template
# Used for UI, and have all the URLs

views = Blueprint('views', __name__)

# nameOfBluePrint.route
@views.route('/')
def home(): # this function runs when we go to the above route in the decorator
    return render_template("home.html")