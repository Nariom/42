from django.conf.urls import patterns, include, url

from main import views

urlpatterns = patterns('',
    url(r'^$', views.index, name='index'),
    url(r'^deconnect', views.deconnect, name='deconnect'),
    url(r'^register', views.register, name='register'),
    url(r'^contact', views.contact, name='contact'),
)