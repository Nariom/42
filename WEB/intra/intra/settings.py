"""
Django settings for intra project.

For more information on this file, see
https://docs.djangoproject.com/en/1.6/topics/settings/

For the full list of settings and their values, see
https://docs.djangoproject.com/en/1.6/ref/settings/
"""

# Build paths inside the project like this: os.path.join(BASE_DIR, ...)
import os

BASE_DIR = os.path.dirname(os.path.dirname(__file__))


# Quick-start development settings - unsuitable for production
# See https://docs.djangoproject.com/en/1.6/howto/deployment/checklist/

# SECURITY WARNING: keep the secret key used in production secret!
SECRET_KEY = 'ao#v*ks3e!p4shc^uczkgnp0idq9-b_#yr053-#%jijt6zog7m'

# SECURITY WARNING: don't run with debug turned on in production!
DEBUG = True

TEMPLATE_DEBUG = True

ALLOWED_HOSTS = []


# Application definition

INSTALLED_APPS = (
    'django_su',
    'django.contrib.admin',
    'django.contrib.auth',
    'django.contrib.contenttypes',
    'django.contrib.sessions',
    'django.contrib.messages',
    'django.contrib.staticfiles',
    'localflavor',
    'tracking',
    'main',
    'forum',
)

MIDDLEWARE_CLASSES = (
    'tracking.middleware.VisitorTrackingMiddleware',
    'django.contrib.sessions.middleware.SessionMiddleware',
    'django.middleware.locale.LocaleMiddleware',
    'django.middleware.common.CommonMiddleware',
    'django.middleware.csrf.CsrfViewMiddleware',
    'django.contrib.auth.middleware.AuthenticationMiddleware',
    'django.contrib.messages.middleware.MessageMiddleware',
    'django.middleware.clickjacking.XFrameOptionsMiddleware',
)

ROOT_URLCONF = 'intra.urls'

WSGI_APPLICATION = 'intra.wsgi.application'


# Database
# https://docs.djangoproject.com/en/1.6/ref/settings/#databases

DATABASES = {
    'default': {
        'ENGINE': 'django.db.backends.mysql',
        'NAME': 'intra',
        'USER': 'root',
        'PASSWORD': 'root',
        'HOST': '127.0.0.1',
        'PORT': '',
    }
}

# Internationalization
# https://docs.djangoproject.com/en/1.6/topics/i18n/

LANGUAGE_CODE = 'en-us'

TIME_ZONE = 'Europe/Paris'

USE_I18N = True

USE_L10N = True

USE_TZ = True

# Media files
MEDIA_ROOT = '/nfs/zfs-student-4/users/2013/rbaudot/DjangoStack/apps/django/django_projects/intra/media/'
MEDIA_URL = 'local.42.fr:8080/media/'

# Static files (CSS, JavaScript, Images)
# https://docs.djangoproject.com/en/1.6/howto/static-files/

STATIC_ROOT = '/nfs/zfs-student-4/users/2013/rbaudot/DjangoStack/apps/django/django_projects/intra/static/'
STATIC_URL = '/static/'

# Templates files

TEMPLATE_DIRS = '/nfs/zfs-student-4/users/2013/rbaudot/DjangoStack/apps/django/django_projects/intra/templates/'

# MAIL

EMAIL_USE_TLS = True
EMAIL_HOST = 'smtp.gmail.com'
EMAIL_HOST_USER = 'test42.rbaudot@gmail.com'
EMAIL_PORT = 587
EMAIL_HOST_PASSWORD = '42test42'

AUTH_PROFILE_MODULE = "main.UserProfile"

# LDAP

import ldap
from django_auth_ldap.config import LDAPSearch, PosixGroupType

AUTH_LDAP_GLOBAL_OPTIONS = {
    ldap.OPT_X_TLS_REQUIRE_CERT: False,
    ldap.OPT_REFERRALS: False,
}

# Baseline configuration.
AUTH_LDAP_SERVER_URI = 'ldaps://ldap.42.fr:636'

AUTH_LDAP_BIND_DN = "uid=rbaudot,ou=2013,ou=people,dc=42,dc=fr"
AUTH_LDAP_BIND_PASSWORD = ""
AUTH_LDAP_USER_DN_TEMPLATE = "uid=%(user)s,ou=2013,ou=people,dc=42,dc=fr"

# Set up the basic group parameters.
AUTH_LDAP_GROUP_SEARCH = LDAPSearch("ou=2013,ou=people,dc=42,dc=fr",
    ldap.SCOPE_SUBTREE, "(objectClass=PosixGroup)"
)
AUTH_LDAP_GROUP_TYPE = PosixGroupType()

# Populate the Django user from the LDAP directory.
AUTH_LDAP_USER_ATTR_MAP = {
    "first_name": "first-name",
    "last_name": "last-name",
    "email": "email-address"
}

AUTH_LDAP_PROFILE_ATTR_MAP = {
    "birth_date": "birth-date",
    "birth_place": "birth-place",
    "city": "city",
    "complete_name": "cn",
    "country": "country",
    "email_address": "email-address",
    "emergency_city": "emergency-city",
    "emergency_country": "emergency-country",
    "emergency_email_address": "emergency-email-address",
    "emergency_first_name": "emergency-first-name",
    "emergency_home_phone": "emergency-home-phone",
    "emergency_last_name": "emergency-last-name",
    "emergency_mobile_phone": "emergency-mobile-phone",
    "emergency_postal_address": "emergency-postal-address",
    "emergency_postal_code": "emergency-postal-code",
    "father_city": "father-city",
    "father_country": "father-country",
    "father_email_address": "father-email-address",
    "father_first_name": "father-first-name",
    "father_home_phone": "father-home-phone",
    "father_last_name": "father-last-name",
    "father_mobile_phone": "father-mobile-phone",
    "father_postal_address": "father-postal-address",
    "father_postal_code": "father-postal-code",
    "gender": "gender",
    "mobile_phone": "mobile-phone",
    "mother_city": "mother-city",
    "mother_country": "mother-country",
    "mother_email_address": "mother-email-address",
    "mother_first_name": "mother-first-name",
    "mother_home_phone": "mother-home-phone",
    "mother_last_name": "mother-last-name",
    "mother_mobile_phone": "mother-mobile-phone",
    "mother_postal_address": "mother-postal-address",
    "mother_postal_code": "mother-postal-code",
    "nationality": "nationality",
    "postal_address": "postal-address",
    "postal_code": "postal-code",
    "security_number": "security-number",
}

# This is the default, but I like to be explicit.
AUTH_LDAP_ALWAYS_UPDATE_USER = True

# Keep ModelBackend around for per-user permissions and maybe a local
# superuser.
AUTHENTICATION_BACKENDS = (
    'django_auth_ldap.backend.LDAPBackend',
    'django.contrib.auth.backends.ModelBackend',
    'django_su.backends.SuBackend',
)

LOGGING = {
    'version': 1,
    'disable_existing_loggers': False,
    'formatters': {
        'verbose': {
            'format' : "[%(asctime)s] %(levelname)s [%(name)s:%(lineno)s] %(message)s",
            'datefmt' : "%d/%b/%Y %H:%M:%S"
        },
        'simple': {
            'format': '%(levelname)s %(message)s'
        },
    },
    'handlers': {
        'file': {
            'level': 'DEBUG',
            'class': 'logging.FileHandler',
            'filename': os.path.join(BASE_DIR, 'intra.log'),
            'formatter': 'verbose'
        },
    },
    'loggers': {
        'django': {
            'handlers':['file'],
            'propagate': True,
            'level':'DEBUG',
        },
        'main': {
            'handlers': ['file'],
            'level': 'DEBUG',
        },
        'forum': {
            'handlers': ['file'],
            'level': 'DEBUG',
        },
    }
}

import logging

logger = logging.getLogger('django_auth_ldap')
logger.addHandler(logging.StreamHandler())
logger.setLevel(logging.DEBUG)

AJAX_LOOKUP_CHANNELS = {'django_su':  dict(model='auth.user', search_field='username')}

TRACK_AJAX_REQUESTS = True
TRACK_ANONYMOUS_USERS = True
TRACK_PAGEVIEWS = True
