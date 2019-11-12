from django.db import models
from django.contrib.auth.models import User

class Item(models.Model):
	name = models.CharField(max_length=50)
	rank = models.IntegerField()
	def __unicode__(self):
		return self.name
	class Meta:
		abstract = True

class Category(Item):
	parent = models.ForeignKey('self', null=True, blank=True)
	class Meta:
		verbose_name_plural = "Categories"
		ordering = ['-rank', 'name']

class Thread(Item):
	parent = models.ForeignKey(Category)
	date = models.DateTimeField()
	def get_author(self):
		return Post.objects.filter(parent_id=self.id)[0]
	class Meta:
		ordering = ['-rank', '-date', 'name']

class Message(models.Model):
	author = models.ForeignKey(User)
	message = models.TextField()
	date = models.DateTimeField()
	def __unicode__(self):
		return self.message[0:12] + '...'
	class Meta:
		abstract = True
		ordering = ['date']

class Post(Message):
	parent = models.ForeignKey(Thread)
	def get_cmt(self):
		return Comment.objects.filter(parent_id=self.id)

class Comment(Message):
	parent = models.ForeignKey(Post)

class Ticket(models.Model):
	author = models.ForeignKey(User, related_name='+')
	assign = models.ForeignKey(User, limit_choices_to={'is_staff': True}, null=True, blank=True, related_name='+')
	status = models.BooleanField()
	date = models.DateTimeField()
	def __unicode__(self):
		return 'Ticket#' + str(self.id)
	class Meta:
		ordering = ['status', 'date']

class TicketMessage(Message):
	parent = models.ForeignKey(Ticket)