from jinja2 import Template

devices = [{"name": "Intel core i5", "price": 20000},
           {"name": "Ryzen 5", "price": 15000},
           {"name": "Intel core i7", "price": 30000},
           {"name": "Ryzen 7", "price": 25000}]

link = '''
{%- for device in devices -%}
    {% if device["price"] > 20000 -%}
    Device: {{device["name"]}}, price: {{device["price"]}}
    {% endif -%}
{% endfor %}'''

tm = Template(link)
message = tm.render(devices = devices)

print(message)