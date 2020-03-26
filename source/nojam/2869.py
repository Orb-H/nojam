import math
a, b, v = map(int, input().split())
print(1 + math.ceil((v - a) / (a - b)))