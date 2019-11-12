from django import template
register = template.Library()

@register.filter
def get(mapping, key):
  res = mapping.get(key, '')
  if res:
  	return res[0]
  else:
  	return res