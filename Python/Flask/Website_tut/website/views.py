from flask import Blueprint, jsonify, render_template, request, flash
from flask_login import login_required, current_user
from .models import Note
from . import db
import json
# Used for UI, and have all the URLs

views = Blueprint('views', __name__)

# nameOfBluePrint.route
@views.route('/', methods = ['GET', 'POST'])
@login_required
def home(): # this function runs when we go to the above route in the decorator
    if request.method == 'POST':
        note = request.form.get('note')
        
        if len(note) < 1:
            flash('Note is too short!', category='error')
        else:
            new_note = Note(data = note, user_id = current_user.id)
            db.session.add(new_note)
            db.session.commit()
            flash('Note Added!', category='success')
    
    return render_template("home.html", user = current_user)

@views.route('/delete-note', methods=['POST'])
def delete_note():
    note = json.loads(request.data)
    noteId = note['noteId']
    note = Note.query.get(noteId)
    
    if note:
        if note.user_id == current_user.id:
            db.session.delete(note)
            db.session.commit()
            
    return jsonify({})