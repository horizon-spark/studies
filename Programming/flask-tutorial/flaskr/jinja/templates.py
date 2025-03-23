from jinja2 import Template

name = "Tom"
position = 3
tmp = Template("Hello, {{ user }}, your position in queue is {{ pos }}")
message = tmp.render(user = name, pos = position)
print(message)