import sys
import os 
# 将运行路径设为脚本所在路径
cur_dirpath=os.path.dirname(os.path.abspath(__file__))
print(cur_dirpath)
os.chdir(cur_dirpath)
# os.chdir(cur_dirpath[:-len(cur_dirpath.split("\\")[-1])]) 
sys.path.append('.')


from urllib import request 
response=request.urlopen('http://www.baidu.com') 
content=response.read()
# print(content)#将会print整个网页的html源码

from collections import deque

queue = deque(['队列元素1','队列元素2','队列元素3'])
queue.append('队列元素4')
queue.popleft()
print(queue)

import re

if re.match(r'href=\".*view\.sdu\.edu\.cn.*\"','href="http://www.view.sdu.edu.cn/new/"'):
    print('ok')
else:
    print('failed')

import sqlite3 
conn=sqlite3.connect('databasetest.db') 
c=conn.cursor() 
#删除原先存在的表
c.execute("drop table if exists doc") 
#创建一个表 
c.execute('create table doc (id int primary key,link text)') 
#往表格插入一行数据 
num=1 
link='www.baidu.com' 
c.execute('insert into doc values (?,?)',(num,link)) 
#查询表格内容 
c.execute('select * from doc') 
#得到查询结果 
result=c.fetchall() 
print(type(result),result) 
conn.commit() 
conn.close()
