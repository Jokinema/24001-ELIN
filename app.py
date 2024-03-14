from flask import Flask, render_template

app = Flask(__name__)

@app.route("/")
@app.route("/index")
def index():
	return render_template("routes/index.html")

@app.route("/register")
def register():
	return render_template("routes/register.html")



@app.route("/dashboard/")
@app.route("/dashboard/index")
def dashboard():
	return render_template("routes/dashboard/index.html")




if __name__ == '__main__':
	app.run(debug=True, host='0.0.0.0')