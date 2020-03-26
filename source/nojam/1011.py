import math
t = int(input())
for i in range(t):
    x, y = map(int, input().split())
    z = y - x
    n = int(z**0.5)
    print(2 * n - 1 if z == n**2 else 2 * n if z <= n**2 + n else 2 * n + 1)