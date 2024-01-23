from flask import Blueprint, render_template, request, flash
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

@auth.route('/sign-up')
def sign_up():
    if request.method == 'POST':
        email = request.form.get('email')
        first_name = request.form.get('firstName')
        password1 = request.form.get('password1')
        password2 = request.form.get('password2')
        
        # now we want to check if the info is valid
        if len(email) < 4:
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
            flash('Account created!', category='success')
        
    return render_template("sign_up.html")