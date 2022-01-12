from flask import Flask, render_template

app = Flask(__name__) 


@app.route('/') 
def index():
    return render_template('index.html')

@app.route('/records', methods = ['POST'] )
def results():
    return render_template('records.html')

@app.route('/') 
def addName(names):
    return render_template('index.html', name2 = names)

def addGrade(user):
    return 0

def editGrade(user):
    return 0

def deleteGrade(user):
    return 0


if __name__ == '__main__':
    app.run(debug = True)






#http://127.0.0.1:5000/
