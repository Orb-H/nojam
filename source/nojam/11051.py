n, k = map(int, input().split())
r = 1
a = []
for i in range(n + 1):
    a.append([1])
    for j in range(1, i):
        a[i].append((a[i - 1][j - 1] + a[i - 1][j]) % 10007)
    a[i].append(1)
print(a[n][k])