from flask import Flask
from flask_sqlalchemy import SQLAlchemy
from os import path
from flask_login import LoginManager

db = SQLAlchemy()
DB_NAME = "database.db"

def create_app():
    app = Flask(__name__)
    app.config['SECRET_KEY'] = 'gsldf glsdfgsjfg'
    app.config['SQLALCHEMY_DATABASE_URI'] = f'sqlite:///{DB_NAME}'
    db.init_app(app)
    
    from .views import views
    from .auth import auth

    app.register_blueprint(views, url_prefix='/')
    app.register_blueprint(auth, url_prefix='/')
    
    # to check if database is created
    from .models import User, Note
    
    with app.app_context():
        print("hi")
        db.create_all()
        
    login_manager = LoginManager()
    login_manager.login_view = 'auth.login' # where do we go if not logged in
    login_manager.init_app(app) # telling the login manager, which app we are using
    
    # this is telling flask how we load a user
    # and by default, it looks for the primary key, which is the int version of the id
    @login_manager.user_loader
    def load_user(id):
        return User.query.get(int(id))
    
    return app