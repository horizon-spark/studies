# (1)
# class Rectangle:
#     def __init__(self,width,length):

#         self.width = width
#         self.length = length

#     def area(self):
#         return self.width * self.length
#     def perimeter(self):
#         return 2 * (self.width + self.length)
    
# r1 = Rectangle(4,5)
# r2 = Rectangle(6,9)
# print("Area1 =",r1.area())
# print("Perimter1 =",r1.perimeter())
# print("Area2 =",r2.area())
# print("Perimeter2 =",r2.perimeter())

# (2)
class BankAccount:
    def __init__(self,num,bal):
        self.account_number = num
        self.balance = bal
        print(f"The new account is created. Initial balance is {bal}")
    def add(self,sum):
        self.balance += sum
        print(f"Balance is increased by {sum}")
    def withdraw(self,sum):
        if sum <= self.balance:
            self.balance -= sum
            print(f"Balance is decreased by {sum}")
        else: 
            print("Impossible to withdraw - not enough money")        

acc1 = BankAccount("123456577", 1000)
acc1.add(200)
acc1.withdraw(500)
acc1.withdraw(300)
acc1.withdraw(900)