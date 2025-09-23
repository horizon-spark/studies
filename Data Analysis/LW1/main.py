import matplotlib.pyplot as plt

f = open('input.txt')
year = []
data = []
for line in f:
    arr = line.split(' ')
    year.append(int(arr[0]))
    data.append(int(arr[1]))
plt.scatter(year,data)
plt.xlabel('Год')
plt.ylabel('Прожиточный минимум, руб')
plt.show()