import sqlite3

def dbhandle():
    conn = sqlite3.connect('db.sqlite3')
    return conn