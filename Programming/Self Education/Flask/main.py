from flask import Flask, render_template, url_for # type: ignore

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/about')
def about():
    return render_template('about.html', about = "About the website")

@app.route('/profile/<username>')
def profile(username):
    return f"This is a profile of {username}"

with app.test_request_context():
    print(url_for('index'))
    print(url_for('about'))
    print(url_for('profile', username = 'user1'))

if __name__ == "__main__":
    app.run(debug=True)