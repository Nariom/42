from django.conf.urls import patterns, include, url
from django.contrib.staticfiles.urls import staticfiles_urlpatterns
from django.contrib import admin
admin.autodiscover()

urlpatterns = patterns('',
    url(r'^$', include('main.urls')),
    url(r'^index/', include('main.urls')),
    url(r'^admin/', include(admin.site.urls)),
    url(r'^agora/', include('forum.urls')),
    url(r'^i18n/', include('django.conf.urls.i18n')),
    url(r"^su/", include("django_su.urls")),
    url(r'^tracking/', include('tracking.urls')),
)

urlpatterns += staticfiles_urlpatterns()
