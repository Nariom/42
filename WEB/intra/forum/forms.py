from django.forms import ModelForm
from forum.models import Thread, Post, Comment, Ticket, TicketMessage

class ThreadForm(ModelForm):
	class Meta:
		model = Thread
		fields = ['name']

class PostForm(ModelForm):
	class Meta:
		model = Post
		fields = ['message']

class CommentForm(ModelForm):
	class Meta:
		model = Comment
		fields = ['message']

class ThreadForm(ModelForm):
	class Meta:
		model = Thread
		fields = ['name']

class TicketMessageForm(ModelForm):
	class Meta:
		model = TicketMessage
		fields = ['message']