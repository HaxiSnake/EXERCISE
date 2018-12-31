from articles import views
import haystack
from django.urls import path,include
urlpatterns = [
    path('query/', views.query),
    path('search/', include('haystack.urls')),
]