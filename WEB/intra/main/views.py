from django.shortcuts import render, redirect
from django.contrib.auth import authenticate, login, logout
from django.contrib.auth.forms import AuthenticationForm, UserCreationForm
from django.contrib.auth.models import User
from django.core.urlresolvers import reverse
from main.forms import ContactForm
from django.core.mail import send_mail
from django.utils import translation
from base64 import b64decode
from django.core.files.base import ContentFile

import logging
logger = logging.getLogger(__name__)

def index(request):
	error = ''
	if request.method == 'POST':
		form = AuthenticationForm(request.POST)
		uid = request.POST['username']
		password = request.POST['password']
		if uid and password:
			user = authenticate(username=uid, password=password)
			if user is not None:
				login(request, user)
				if user.get_profile().language:
					code = user.get_profile().language
				else:
					code = 'en'
				translation.activate(code)
				request.session['django_language'] = code
				#try:
				#	image_data = b64decode(user.ldap_user.attrs['picture'][0])
				#except AttributeError:
				#	image_data = None
				#else:
				#	user.get_profile().picture = ContentFile(image_data, user.username + '.png')
				#	user.get_profile().save()
			else:
				error = 'Wrong username or password.'
		else:
			error = 'Both fields are required.'
	else:
		form = AuthenticationForm()
	return render(request, 'index.html', locals())

def deconnect(request):
	request.user.get_profile().language = request.LANGUAGE_CODE
	request.user.get_profile().save()
	logout(request)
	return redirect(reverse(index))

def register(request):
	error = ''
	if request.method == 'POST':
		form = UserCreationForm(request.POST)
		if request.POST['username'] and request.POST['password1'] and request.POST['password2']:
			try:
				User.objects.get(username=request.POST['username'])
			except (KeyError, User.DoesNotExist):
				if request.POST['password1'] != request.POST['password2']:
					error = 'Password confirmation does not match.'
				else:
					user = User.objects.create_user(request.POST['username'], '', request.POST['password1'])
					user.save()
					return redirect(reverse(index))
			else:
				error = 'Username already registered.'
		else:
			error = 'All fields are required.'
	else:
		form = UserCreationForm()
	return render(request, 'register.html', locals())

def contact(request):
	if not request.user.is_authenticated():
		return redirect(reverse(index))
	else:
		if request.method == 'POST':
			form = ContactForm(request.POST)
			if form.is_valid():
				cd = form.cleaned_data
				send_mail(cd['subject'], cd['message'], 'test42.rbaudot@gmail.com', ['test42.rbaudot@gmail.com', cd['email']])
				return redirect(reverse(index))
		else:
			form = ContactForm() 
		return render(request, 'contact.html', locals())