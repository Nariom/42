from django.shortcuts import render, redirect
from django.core.urlresolvers import reverse
from forum.models import Category, Thread, Post, Comment, Ticket, TicketMessage
from forum.forms import ThreadForm, PostForm, CommentForm, TicketMessageForm
import datetime
import main.views
import ldap
from django.conf import settings

def agora(request, cat_id=None, thd_id=None):
	if not request.user.is_authenticated():
		return redirect(reverse(main.views.index))
	else:
		if cat_id:
			try:
				cat = Category.objects.get(pk=cat_id)
			except Category.DoesNotExist:
				return redirect(reverse(agora))
			name = cat.name
			parent = cat.parent_id
		cat_list = Category.objects.filter(parent=cat_id)
		if thd_id:
			msg_list = Post.objects.filter(parent=thd_id)
			try:
				thd = Thread.objects.get(pk=thd_id)
			except Thread.DoesNotExist:
				url = ''.join(('/agora/', str(cat_id), '/'))
				return redirect(url, request)
			tname = thd.name
			if request.method == 'POST':
				form = PostForm(request.POST)
				if form.is_valid():
					date = datetime.datetime.now()
					new = form.save(commit=False)
					new.author = request.user
					new.date = date
					new.parent = thd
					new.save()
					thd.date = date
					thd.save()
			else:
				form = PostForm()
		else:
			thd_list = Thread.objects.filter(parent=cat_id)
		return render(request, 'agora.html', locals())

def newthread(request, cat_id):
	if not request.user.is_authenticated():
		return redirect(reverse(index))
	else:
		try:
			cat = Category.objects.get(pk=cat_id)
		except Category.DoesNotExist:
			return redirect(reverse(ticket))
		if request.method == 'POST':
			tform = ThreadForm(request.POST, prefix="thd")
			pform = PostForm(request.POST, prefix="pst")
			if tform.is_valid() and pform.is_valid():
				date = datetime.datetime.now()
				newt = tform.save(commit=False)
				newt.rank = 0
				newt.parent = cat
				newt.date = date
				newt.save()
				newp = pform.save(commit=False)
				newp.author = request.user
				newp.date = date
				newp.parent = newt
				newp.save()
				url = ''.join(('/agora/', str(cat_id), '/', str(newt.id), '/'))
				return redirect(url, request)
		else:
			tform = ThreadForm(prefix="thd")
			pform = PostForm(prefix="pst")
		return render(request, 'newthread.html', locals())

def newcomment(request, cat_id, thd_id, pst_id):
	if not request.user.is_authenticated():
		return redirect(reverse(index))
	else:
		try:
			post = Post.objects.get(pk=pst_id)
		except Post.DoesNotExist:
			url = ''.join(('/agora/', str(cat_id), '/', str(thd_id), '/'))
			return redirect(url, request)
		if request.method == 'POST':
			form = CommentForm(request.POST)
			if form.is_valid():
				new = form.save(commit=False)
				new.author = request.user
				new.date = datetime.datetime.now()
				new.parent = post
				new.save()
				url = ''.join(('/agora/', str(cat_id), '/', str(thd_id), '/'))
				return redirect(url, request)
		else:
			form = CommentForm()
		return render(request, 'newcomment.html', locals())

def ticket(request, tkt_id=None):
	if not request.user.is_authenticated():
		return redirect(reverse(main.views.index))
	else:
		if tkt_id:
			try:
				tkt = Ticket.objects.get(pk=tkt_id)
			except Ticket.DoesNotExist:
				return redirect(reverse(ticket))
			if tkt.author != request.user:
				return redirect(reverse(ticket))
			msg_list = TicketMessage.objects.filter(parent=tkt_id)
			if request.method == 'POST':
				form = TicketMessafeForm(request.POST)
				if form.is_valid():
					date = datetime.datetime.now()
					new = form.save(commit=False)
					new.author = request.user
					new.date = date
					new.parent = tkt
					new.save()
					tkt.date = date
					tkt.save()
			else:
				form = PostForm()
		else:
			tkt_list = Ticket.objects.filter(author=request.user)
		return render(request, 'ticket.html', locals())

def newticket(request):
	if not request.user.is_authenticated():
		return redirect(reverse(index))
	else:
		if request.method == 'POST':
			form = TicketMessageForm(request.POST)
			if form.is_valid():
				date = datetime.datetime.now()
				newt = Ticket.objects.create(author=request.user, assign=None, status=True, date=date)
				newm = form.save(commit=False)
				newm.author = request.user
				newm.date = date
				newm.parent = newt
				newm.save()
				url = ''.join(('/agora/ticket/', str(newt.id), '/'))
				return redirect(url, request)
		else:
			form = TicketMessageForm()
		return render(request, 'newticket.html', locals())

def status(request, tkt_id):
	if not request.user.is_authenticated():
		return redirect(reverse(index))
	else:
		try:
			tkt = Ticket.objects.get(pk=tkt_id)
		except Ticket.DoesNotExist:
			return redirect(reverse(ticket))
		if tkt.author != request.user:
			return redirect(reverse(ticket))
		tkt.status = not tkt.status
		tkt.save()
		url = ''.join(('/agora/ticket/', str(tkt.id), '/'))
		return redirect(url, request)

def directory(request):
	if not request.user.is_authenticated():
		return redirect(reverse(index))
	else:
		results = None
		if request.method == 'POST':
			filters = '(uid=' + request.POST['uid']
			filters += '*'
			filters += ')'
			ldap.set_option(ldap.OPT_PROTOCOL_VERSION,ldap.VERSION3)
			ldap.set_option(ldap.OPT_X_TLS_REQUIRE_CERT,False)
			ld = ldap.initialize('ldaps://ldap.42.fr:636')
			ld.simple_bind_s(settings.AUTH_LDAP_BIND_DN, settings.AUTH_LDAP_BIND_PASSWORD)
			results = ld.search_s('ou=2013,ou=people,dc=42,dc=fr',ldap.SCOPE_SUBTREE,filters,['picture', 'uid', 'cn', 'email-address', 'mobile-phone'])
			if results:
				tab = ['', '', '', '', '']
				if 'picture' in results[0][1] :
					tab[0] = results[0][1]['picture'][0].encode('base64')
				if 'uid' in results[0][1] :
					tab[1] = results[0][1]['uid'][0]
				if 'cn' in results[0][1] :
					tab[2] = results[0][1]['cn'][0]
				if 'email-address' in results[0][1] :
					tab[3] = results[0][1]['email-address'][0]
				if 'mobile-phone' in results[0][1] :
					tab[4] = results[0][1]['mobile-phone'][0]
		return render(request, 'directory.html', locals())
