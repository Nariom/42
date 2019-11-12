from django.contrib import admin
from forum.models import Category, Thread, Post, Comment, Ticket, TicketMessage

class ItemAdmin(admin.ModelAdmin):
	fieldsets = [
		('Content', {'fields' : ['name', 'rank']}),
		('Parent', 	{'fields' : ['parent']}),
	]
	list_display = ('name', 'rank', 'parent')
	list_filter = ['rank', 'parent']
	search_fields = ['name']

class ThreadAdmin(admin.ModelAdmin):
	fieldsets = [
		('Content', {'fields' : ['name', 'rank', 'date']}),
		('Parent', 	{'fields' : ['parent']}),
	]
	list_display = ('name', 'rank', 'parent', 'date')
	list_filter = ['rank', 'parent', 'date']
	search_fields = ['name']

class MessageAdmin(admin.ModelAdmin):
	fieldsets = [
		('Content',	{'fields' : ['author', 'message', 'date']}),
		('Parent', 	{'fields' : ['parent']}),
	]
	list_display = ('author', 'date', 'parent')
	list_filter = ['date', 'parent']
	search_fields = ['author__username']

class TicketInline(admin.StackedInline):
	model = TicketMessage
	extra = 1

class TicketAdmin(admin.ModelAdmin):
	fieldsets = [
		('Users', {'fields' : ['author', 'assign']}),
		('Date', {'fields' : ['date'], 'classes' : ['collapse']}),
		('Status', {'fields' : ['status']}),
	]
	list_display = ('author', 'assign', 'status', 'date')
	list_filter = ['status', 'date']
	search_fields = ['author__username', 'assign__username']
	inlines = [TicketInline]

admin.site.register(Category, ItemAdmin)
admin.site.register(Thread, ThreadAdmin)
admin.site.register(Post, MessageAdmin)
admin.site.register(Comment, MessageAdmin)
admin.site.register(Ticket, TicketAdmin)
