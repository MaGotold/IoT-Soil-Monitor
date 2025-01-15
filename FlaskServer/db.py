import sqlite3
from datetime import datetime

# DB setup
DB_NAME = "sensor_data.db"

def create_table():
    conn = sqlite3.connect(DB_NAME)
    cursor = conn.cursor()
    cursor.execute('''
    CREATE TABLE IF NOT EXISTS sensor_data (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        temperature REAL,
        humidity REAL,
        el_conductivity REAL,
        timestamp DATETIME
    )
    ''')
    conn.commit()
    conn.close()
    

def insert_data(temp, hum, cond, timestamp):
    conn = sqlite3.connect("sensor_data.db")
    cursor = conn.cursor()

    formattedTimestamp = datetime.strptime(timestamp, "%Y-%m-%d %H:%M:%S")
    

    cursor.execute('''
        INSERT INTO sensor_data (temperature, humidity, el_conductivity, timestamp)
        VALUES (?, ?, ?, ?)
    ''', (temp, hum, cond, formattedTimestamp))
    conn.commit()
    conn.close()
    
    