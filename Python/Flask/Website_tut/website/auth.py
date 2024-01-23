from flask import Blueprint, render_template, request, flash, redirect, url_for
from .models import User
from werkzeug.security import generate_password_hash, check_password_hash
from . import db
# this is why we needed UserMixin
from flask_login import login_user, login_required, logout_user, current_user
# Used for UI, and have all the URLs

auth = Blueprint('auth', __name__)

# by default method accepted are only GET, but now, we can accept both GET and POST requests
@auth.route('/login', methods=['GET', 'POST'])
def login():
    # we only want to store info in a POST request
    if request.method == 'POST':
        email = request.form.get('email') # names
        password = request.form.get('password')
        
        user = User.query.filter_by(email = email).first()
        if user:
            if check_password_hash(user.password, password):
                flash('Logged in successfully!', category='success')
                login_user(user, remember=True)
                # this remembers the fact that the user is logged in
                return redirect(url_for('views.home'))    
            else:
                flash('Incorrect password, try again.', category='error')
        else:
            flash('Email does not exist.', category='error')
        
    return render_template("login.html")

@auth.route('/logout')
@login_required # we don't want to access this page unless logged in. so this...
def logout():
    logout_user()
    flash('Logged out successfully!', category='success')
    return redirect(url_for('auth.login'))

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
            return redirect(url_for('auth.login'))
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
            
            login_user(user, remember=True)
            
            flash('Account created!', category='success')
            return redirect(url_for('views.home'))
        
    return render_template("sign_up.html")