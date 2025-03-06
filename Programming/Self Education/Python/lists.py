# (1)
#  names = ["Jane", "Lawrance", "Robert"]
# names.append("Michael")
# names.append("John")
# names.pop()
# print(names)

# (2)
# mat = [
#     [10, 20, 30],
#     [40, 50, 60],
#     [70, 80, 80]
# ]
# print(mat)

# print(f"mat[0]: {mat[0]}")
# print(f"mat[1]: {mat[1]}")
# print(f"mat[2]: {mat[2]}")

# print(f"mat[0][0]: {mat[0][0]}")

# (3)
# mat = [
#     [10, 20, 30],
#     [40, 50, 60],
#     [70, 80, 80]
# ]
# for line in mat:
#     for elem in line:
#         print(elem,end = " ")
#     print()

# (4)
# init = [10, 20, 10, 20, 30, 40, 30, 50]
# res = []
# for elem in init:
#     if elem not in res:
#         res.append(elem)
# print(res)

# (5)
# numbers = [1,2,3,4,5]
# for i in range(10):
#     numbers.append(i+1)
# squares = map(lambda n: n * n, numbers)
# cubes = map(lambda n: n * n * n, numbers)
# print(f"numbers: {numbers}")
# print("squares: [", end = " ")
# for item in squares:
#     print(item, end = " ")
# print("]")
# print("cubes: [", end = " ")
# for item in cubes:
#     print(item, end = " ")
# print("]")

# (6)
# numbers = [10, 20, 30, 40, 50]
# rev_numbers = numbers[:]
# rev_numbers.reverse()
# print(numbers)
# print(rev_numbers)

# (7)
# init = [11, 22, 33, 44, 55]
# print(init)
# res = filter(lambda n: n % 2 != 0, init)
# for elem in res: print(elem, end = " ")

# (8)
# def add_lists(list1, list2):
#     res = []
#     for i in range(len(list1)):
#         res.append(list1[i] + list2[i])
#     return res
# print(add_lists([1, 2, 3, 4],[5, 6, 7, 8]))

# (9)
def scalar_mult(list1, list2):
    res = 0
    for i in range(len(list1)):
        res += (list1[i] * list2[i])
    return res
print(scalar_mult([1, 2, 3, 4],[5, 6, 7, 8]))
