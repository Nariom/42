from django.db import models
from django.contrib.auth.models import User
from django.db.models.signals import post_save

class UserProfile(models.Model):
	user = models.OneToOneField(User)
	language = models.CharField(max_length=5, null=True, blank=True)
	birth_date = models.CharField(max_length=15, null=True, blank=True)
	birth_place = models.CharField(max_length=50, null=True, blank=True)
	city = models.CharField(max_length=50, null=True, blank=True)
	complete_name = models.CharField(max_length=61, null=True, blank=True)
	country = models.CharField(max_length=50, null=True, blank=True)
	email_address = models.CharField(max_length=250, null=True, blank=True)
	emergency_city = models.CharField(max_length=50, null=True, blank=True)
	emergency_country = models.CharField(max_length=50, null=True, blank=True)
	emergency_email_address = models.CharField(max_length=250, null=True, blank=True)
	emergency_first_name = models.CharField(max_length=30, null=True, blank=True)
	emergency_home_phone = models.CharField(max_length=10, null=True, blank=True)
	emergency_last_name = models.CharField(max_length=30, null=True, blank=True)
	emergency_mobile_phone = models.CharField(max_length=10, null=True, blank=True)
	emergency_postal_address = models.CharField(max_length=100, null=True, blank=True)
	emergency_postal_code = models.CharField(max_length=5, null=True, blank=True)
	father_city = models.CharField(max_length=50, null=True, blank=True)
	father_country = models.CharField(max_length=50, null=True, blank=True)
	father_email_address = models.CharField(max_length=250, null=True, blank=True)
	father_first_name = models.CharField(max_length=30, null=True, blank=True)
	father_home_phone = models.CharField(max_length=10, null=True, blank=True)
	father_last_name = models.CharField(max_length=30, null=True, blank=True)
	father_mobile_phone = models.CharField(max_length=10, null=True, blank=True)
	father_postal_address = models.CharField(max_length=100, null=True, blank=True)
	father_postal_code = models.CharField(max_length=5, null=True, blank=True)
	gender = models.CharField(max_length=6, null=True, blank=True)
	mobile_phone = models.CharField(max_length=10, null=True, blank=True)
	mother_city = models.CharField(max_length=50, null=True, blank=True)
	mother_country = models.CharField(max_length=50, null=True, blank=True)
	mother_email_address = models.CharField(max_length=250, null=True, blank=True)
	mother_first_name = models.CharField(max_length=30, null=True, blank=True)
	mother_home_phone = models.CharField(max_length=10, null=True, blank=True)
	mother_last_name = models.CharField(max_length=30, null=True, blank=True)
	mother_mobile_phone = models.CharField(max_length=10, null=True, blank=True)
	mother_postal_address = models.CharField(max_length=100, null=True, blank=True)
	mother_postal_code = models.CharField(max_length=5, null=True, blank=True)
	nationality = models.CharField(max_length=50, null=True, blank=True)
	picture = models.ImageField(upload_to="/media", null=True, blank=True)
	postal_address = models.CharField(max_length=100, null=True, blank=True)
	postal_code = models.CharField(max_length=5, null=True, blank=True)
	security_number = models.CharField(max_length=15, null=True, blank=True)

def create_user_profile(sender, instance, created, **kwargs):
	if created:
		UserProfile.objects.create(user=instance)

post_save.connect(create_user_profile, sender=User)