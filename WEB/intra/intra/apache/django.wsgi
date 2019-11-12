import os, sys
sys.path.append('/nfs/zfs-student-4/users/2013/rbaudot/DjangoStack/apps/django/django_projects/intra/intra/')
sys.path.append('/nfs/zfs-student-4/users/2013/rbaudot/DjangoStack/apps/django/django_projects/intra/')
os.environ['DJANGO_SETTINGS_MODULE'] = 'intra.settings'

import django.core.handlers.wsgi

application = django.core.handlers.wsgi.WSGIHandler()
