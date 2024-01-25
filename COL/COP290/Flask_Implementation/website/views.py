# this file handels the frontend that is the home page
from flask import Blueprint, jsonify, render_template, request, flash
from flask_login import login_required, current_user
from . import db
import json 

views = Blueprint('views', __name__)

@views.route('/', methods = ['GET', 'POST'])
@login_required
def home():
    return render_template("home.html", user = current_user)