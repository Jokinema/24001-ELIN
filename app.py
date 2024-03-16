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

@app.route("/dashboard/inputData/")
@app.route("/dashboard/inputData/index")
def inputData_index():
	return render_template("routes/dashboard/inputData/1_inputData.html")

@app.route("/dashboard/inputData/rekomendasi")
def inputData_rekomendasi():
	return render_template("routes/dashboard/inputData/3_rekomendasi.html")


@app.route("/dashboard/riwayat/")
@app.route("/dashboard/riwayat/index")
def riwayat_index():
	return render_template("routes/dashboard/riwayat/1_riwayat.html")


if __name__ == '__main__':
	app.run(debug=True, host='0.0.0.0')