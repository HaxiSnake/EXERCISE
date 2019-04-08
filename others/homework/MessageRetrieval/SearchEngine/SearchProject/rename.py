import sqlite3

conn = sqlite3.connect('db.sqlite3')

cursor=conn.cursor()

sql='alter table "search_article" rename to "articles_article"'
try:
    ret=cursor.execute(sql)
    print("success!")
except Exception as e:
    print("failed!")
    print(e)
