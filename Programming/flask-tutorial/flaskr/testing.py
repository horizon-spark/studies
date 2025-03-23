from flask import Flask, request, redirect, url_for, render_template, session # type: ignore


app = Flask(__name__)

def show_the_login_form():
    return "<p>Insert your data</p>"
def do_the_login():
    return "<p>You're already logged in</p>"

@app.route("/")
def index():
    return redirect(url_for('login'))

@app.route("/profiles/<username>/")
def show_profile(username):
    return f"This profile belongs to {username}"

@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        return do_the_login()
    else:
        return show_the_login_form()
    
@app.errorhandler(404)
def page_not_found(error):
    return render_template("page_not_found.html")

# Иначе можно написать так

# @app.get("/login")                  # Отдельно для метода get
# def login_get():
#     return show_the_login_form()

# @app.post("/login")                 # Отдельно для метода post
# def login_post():
#     return do_the_login()

@app.route("/info")
def me_api():
    return {
        "username": "Dmitry",
        "theme": "Dark"
    }

if __name__ == "__main__":
    app.run(debug = "true")