import math
n = int(input())
u = math.ceil((math.sqrt(8 * n + 1) + 1) / 4)
d = math.ceil((math.sqrt(8 * n + 1) - 1) / 4)
a = min(2 * u**2 - u + 1 - n, n - 2 * u**2 + 5 * u - 3)
b = min(2 * d**2 + d + 1 - n, n - 2 * d**2 + 3 * d - 1)
print('{0}/{1}'.format(a, b))