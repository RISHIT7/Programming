from flask import Blueprint, render_template, request, flash, redirect, url_for
from .models import User
from werkzeug.security import generate_password_hash, check_password_hash
from . import db
# Used for UI, and have all the URLs

auth = Blueprint('auth', __name__)

# by default method accepted are only GET, but now, we can accept both GET and POST requests
@auth.route('/login', methods=['GET', 'POST'])
def login():
    # we only want to store info in a POST request
    if request.method == 'POST':
        email = request.form.get('email') # names
        password = request.form.get('password')
        
        
    return render_template("login.html")

@auth.route('/logout')
def logout():
    return "<p>Logout</p>"

@auth.route('/sign-up', methods = ['GET', 'POST'])
def sign_up():
    if request.method == 'POST':
        email = request.form.get('email')
        first_name = request.form.get('firstName')
        password1 = request.form.get('password1')
        password2 = request.form.get('password2')
        
        # now we want to check if the info is valid
        user = User.query.filter_by(email = email).first()
        
        if user:
            flash('Email already exists.', category='error')
        elif len(email) < 4:
            # message flashing
            flash('Email must be greater than 3 characters.', category='error')
        elif len(first_name) < 2:
            flash('First Name must be greater than 1 character.', category='error')
        elif password1 != password2:
            flash('Passwords must match.', category='error')
        elif len(password1) < 7:
            flash('Password must be greater than 6 characters.', category='error')
        else:
            # add user to database
            new_user = User(email=email, first_name=first_name, password=generate_password_hash(
                password1, method='pbkdf2:sha256'))            
            db.session.add(new_user)
            db.session.commit()
            
            
            flash('Account created!', category='success')
            return redirect(url_for('views.home'))
        
    return render_template("sign_up.html")