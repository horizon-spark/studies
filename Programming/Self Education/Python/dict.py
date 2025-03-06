# (1)
# tom = {"Name": "Tom", "Age": 39, "Company": "SuperCorp", "Languages": ["Python", "JavaScript"]}
# for key in tom:
#     print(key,":",tom[key])

# (2)
people = [
    {"name": "Tom", "age": 39, "company": "SuperCorp", "languages": ["Python", "JavaScript"]},
    {"name": "Bob", "age": 43, "company": "BigCorp", "languages": ["Python", "C++", "C#"]},
    {"name": "Sam", "age": 28, "company": "LittleCorp", "languages": ["Python", "Java"]}
]
for person in people:
    print("Name:",person["name"],"\nLast language:",person["languages"][-1])

