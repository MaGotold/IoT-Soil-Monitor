from flask import Flask
from mqtt_client import connect_mqtt
from db import create_table


app = Flask(__name__)


connect_mqtt()

@app.route("/")
def home():
    return "success"


if __name__ == "__main__":
    create_table()
    app.run(host="0.0.0.0", port=5000, debug = True)