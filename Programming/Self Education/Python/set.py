# (1)
# list1 = [10, 20, 30, 40, 50]
# list2 = [20, 25, 30, 35, 40]
# print("list1:",list1)
# print("list2:",list2)
# print("The difference:",list(set(list1) - set(list2)))

# (2)
students = {"Tom", "Bob", "Sam"}
employees = {"Tom", "Bob", "Alex", "Mike"}
print("Total people:",students | employees)
print("Both study and work:",students & employees)
print("Only study:",students - employees)
print("Do only one thing:",students ^ employees)