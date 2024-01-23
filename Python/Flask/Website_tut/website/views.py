from flask import Blueprint, render_template
from flask_login import login_required, current_user
# Used for UI, and have all the URLs

views = Blueprint('views', __name__)

# nameOfBluePrint.route
@views.route('/')
@login_required
def home(): # this function runs when we go to the above route in the decorator
    return render_template("home.html", user = current_user)