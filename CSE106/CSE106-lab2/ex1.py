import numpy as np
#exercise1a
print("a.")
arr = np.arange(2,10).reshape(4,2)
print(arr)

print("\n")

#exercise1b
print("b.")
arr2 = np.zeros((8,8), dtype=int)
arr2[1::2,::2] = 1
arr2[::2,1::2] = 1
print(arr2)

print("\n")

#exercise1c
print("c.")
arr3 = [10, 20, 10, 30, 20, 40, 20, 20, 10, 30, 0, 50, 10]
print("List = ", arr3)
print("Unique List =", np.unique(arr3))

print("\n")

#exercise1d
print("d.")
arr4 = np.array([6, 75, 9, 82, 36, 42, 59, 3, 52, 1, 32, 68, 93, 4, 27, 85, 0, -3, 57])
arr4sorted = np.sort(arr4[arr4 > 37])
print("Values > 37 = ", arr4sorted)

print("\n")

#exercise1e
print("e.")
arr5 = np.array([0, 12, 45.21 ,34, 99.91])
farenheit = (arr5 * 9/5) + 32
print(farenheit)


