from flask import Flask, request, flash, url_for, redirect, render_template, Request
from flask_sqlalchemy import SQLAlchemy
import requests

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///students.db'    
app.config['SECRET_KEY'] = "random string"
db = SQLAlchemy(app)

class students(db.Model):
    name = db.Column(db.String(100), primary_key=True)
    grade = db.Column(db.Integer)

    def __init__(self, name, grade):
        self.name = name
        self.grade = grade

@app.route('/')
def showHome():
    return redirect(url_for('grades')) 

@app.route('/new', methods=['GET'])
def new():
    return render_template('new.html')

@app.route('/edit', methods=['GET'])
def edit():
    return render_template('edit.html')

@app.route('/delete', methods=['GET'])
def delete():
    return render_template('delete.html')

@app.route('/search', methods=['GET'])
def search():
    return render_template('search.html')

@app.route('/editstudent', methods=['GET'])
def editstudent():
    r = requests.put('http://127.0.0.1:5000/grades', request.args)
    return redirect(url_for('grades'))

@app.route('/deletestudent', methods=['GET'])
def deletestudent():
    r = requests.delete('http://127.0.0.1:5000/grades', data={'name':request.args.get('name')})
    return redirect(url_for('grades'))

@app.route('/grades', methods=['GET', 'POST', 'PUT','DELETE'])
def grades():

    if request.method == 'GET': 
        if len(request.args)  == 0:
            return render_template('grades.html', students=students.query.all())
        else: 
            return render_template('grades.html', students=students.query.filter_by(name=request.args.get('name')))

    elif request.method == 'POST':   
        if not request.form['name'] or not request.form['grade'] :
            flash('Please enter all the fields', 'error')
        else:
            student = students(request.form['name'], request.form['grade'])
            db.session.add(student) 
            db.session.commit()                
            flash('Student added successfully.')
            return redirect(url_for('grades'))  

    elif request.method == 'PUT':             
        if not request.form['name'] or not request.form['grade']:   
           flash('Please enter all the fields', 'error')
        else:
            student = students(request.form['name'], request.form['grade'])
            db.session.query(students).filter_by(name=student.name).update({students.grade: student.grade}, synchronize_session=False)
            db.session.commit()          
            flash('Student updated successfully.')
            return redirect(url_for('grades'))

    elif request.method == 'DELETE':            
        if not request.form['name'] :          
           flash('Please enter all the fields', 'error')
        else:
            db.session.query(students).filter_by(name=request.form['name']).delete()
            db.session.commit()
            flash('Student deleted successfully.')
            return redirect(url_for('grades'))

    return render_template('grades.html')

if __name__ == '__main__':
    db.create_all()
    app.run(debug=True)