import math


def fill(a, m, n):
    if m >= n:
        return a
    for i in range(m):
        b = str(a[i])
        a[i] = a[i] * 3
        b = b + ' ' * len(b) + b
        a.append(b)
    for i in range(m):
        a.append(str(a[i]))
    return fill(a, 3 * m, n)


n = int(input())
a = ['*']
a = fill(a, 1, n)
for i in range(n):
    print(a[i])