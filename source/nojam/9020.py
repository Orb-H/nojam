a = [True] * 10001
a[0] = False
a[1] = False
for i in range(2, 10001):
    if a[i]:
        for j in range(2, 10000 // i + 1):
            a[i * j] = False
t = int(input())
for i in range(t):
    n = int(input())
    for i in range(n // 2, 1, -1):
        if a[i] and a[n - i]:
            print('{0} {1}'.format(i, n - i))
            break