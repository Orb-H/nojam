a = [True] * 1000001
a[0] = False
a[1] = False
for i in range(2, 1000001):
    if a[i]:
        for j in range(2, 1000000 // i + 1):
            a[i * j] = False
m, n = map(int, input().split())
for i in range(m, n + 1):
    if a[i]:
        print(i)