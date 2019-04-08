# -*- coding: utf-8 -*-

# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: https://doc.scrapy.org/en/latest/topics/item-pipeline.html

from SpiderProject.sqliteUtils import dbhandle

class SpiderprojectPipeline(object):
    def process_item(self, item, spider):
        if spider.name == 'news':
            conn = dbhandle()
            cursor = conn.cursor()
            title = item['title']
            url = item['url']
            content_tmp = item['content']
            content=""
            for p in content_tmp:
                content+=p.strip()
            sql_search = 'select arturl from search_article where arturl=="%s"' % (url) 
            sql = 'insert into articles_article(title, content, arturl) values("%s", "%s", "%s")'%(title, content, url)
            try:
                #如果当前数据库中不存在该条新闻，则将新闻保存至数据库当中
                cursor.execute(sql_search)
                result_search = cursor.fetchone()
                if result_search is None or result_search[0].strip()=='':
                    cursor.execute(sql)
                    result=cursor.fetchone()
                    conn.commit()
                cursor.execute(sql)
                result=cursor.fetchone()
                conn.commit()
            except Exception as e:
                print(">>> catch exception !")
                print(e)
                conn.rollback()
        return item
