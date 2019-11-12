from django.conf.urls import patterns, url

from forum import views

urlpatterns = patterns('',
	url(r'^$', views.agora, name='agora'),
    url(r'^(?P<cat_id>\d+)/$', views.agora, name='agora'),
    url(r'^(?P<cat_id>\d+)/(?P<thd_id>\d+)/$', views.agora, name='agora'),
    url(r'^(?P<cat_id>\d+)/newthread/$', views.newthread, name='newthread'),
    url(r'^(?P<cat_id>\d+)/(?P<thd_id>\d+)/(?P<pst_id>\d+)/newcomment/$', views.newcomment, name='newcomment'),
    url(r'^ticket/$', views.ticket, name='ticket'),
    url(r'^ticket/(?P<tkt_id>\d+)/$', views.ticket, name='ticket'),
    url(r'^ticket/newticket/$', views.newticket, name='newticket'),
    url(r'^ticket/(?P<tkt_id>\d+)/status/$', views.status, name='status'),
    url(r'^directory/$', views.directory, name='directory'),
)