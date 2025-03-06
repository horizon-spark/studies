class Vector:
    type = "Vector"
    def __init__(self,coordX,coordY):
        self.x = coordX
        self.y = coordY
    def __str__(self):
        return f"Type: {self.type}, x = {self.x}, y = {self.y}"
    def __add__(self,other):
        return Vector(self.x + other.x, self.y + other.y)
    def __sub__(self,other):
        return Vector(self.x - other.x, self.y - other.y)
v1 = Vector(3,-1)
v2 = Vector(-6,7)
print(v1 + v2)
print(v1 - v2)
    