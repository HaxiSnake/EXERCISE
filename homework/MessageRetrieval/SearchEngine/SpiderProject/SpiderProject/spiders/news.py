# -*- coding: utf-8 -*-
import scrapy

from SpiderProject.items import NewsItem
from scrapy.contrib.spiders import CrawlSpider, Rule
from scrapy.linkextractors import LinkExtractor

class NewsSpider(CrawlSpider):
    print("news spider starting")
    name = 'news'
    allowed_domains = ['news.dlut.edu.cn']
    start_urls = ['http://news.dlut.edu.cn/']

    rules = (
        # 对于新闻页链接进行跟进
        Rule(LinkExtractor(allow=("xw/[a-z]+.htm"))),
        # 对于详细新闻页利用parse_item回调函数进行内容爬取
        Rule(LinkExtractor(allow=("info/\d{4,}/\d{3,}\.htm")),callback="parse_item"),
        # 对于新闻列表中的下一页链接进行跟进
        Rule(LinkExtractor(allow=("\d{1,}.htm"),restrict_xpaths="//a[@class='Next']")),
    )

    def parse_item(self, response):
        self.log("Hi, this is a new page! %s"% response.url)
        item = NewsItem()
        item['title'] = response.xpath('/html/head/title/text()').extract()[0]
        item['url'] = response.url
        item['content']=response.xpath("//div[@class='cont-detail fs-small']/p/text()").extract()
        yield item

