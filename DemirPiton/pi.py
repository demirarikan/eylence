import random
import math

print("Please enter the numbers of points to approximate pi:")
b = int(input())
a = 0

for i in range(b):
    x = random.random()
    y = random.random()
    dist = math.sqrt(((x**2)+(y**2)))
    if dist <= 1 : a += 1


pi = ((a/b) * 4)
print(pi)