
''' (1)
year = int(input("Insert a year to check: "))
if year % 400 == 0 or year % 4 == 0 and year % 100 != 0:
    print("The year is leap")
else: 
    print("The year is common")
'''
''' (2)
a = int(input("Insert first number: "))
b = int(input("Insert second number: "))
if (a > b):
    print(f"Наибольшее число: {a}")
else: 
    print(f"Наибольшее число: {b}")
'''
sum = int(input("Insert the sum: "))
if sum <= 5000:
    sale = 0.05
elif sum <= 15000:
    sale = 0.12
elif sum <= 25000:
    sale = 0.2
else:
    sale = 0.3
print(f"Sale is {sum * sale}")
print(f"Sum after applying the sale is {sum - sum * sale}")