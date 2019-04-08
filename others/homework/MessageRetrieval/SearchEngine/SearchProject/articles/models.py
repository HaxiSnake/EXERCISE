from django.db import models

# Create your models here.
class Article(models.Model):
    title = models.CharField(max_length=50)
    arturl = models.CharField(max_length=200)
    content = models.CharField(max_length=1000)