import math, sys


def g(a, b):
    if b > a:
        a, b = b, a
    while b != 0:
        a, b = b, a % b
    return a


n = int(sys.stdin.readline().rstrip())
a = [0] * n
for i in range(n):
    a[i] = int(sys.stdin.readline().rstrip())
a.sort()
m = a[1] - a[0]
for i in range(1, n - 1):
    m = g(m, a[i + 1] - a[i])
r = set()
r.add(m)
z = int(math.sqrt(m))
for i in range(2, z + 1):
    if m % i == 0:
        r.add(i)
        r.add(m // i)
print(' '.join(str(x) for x in sorted(r)))