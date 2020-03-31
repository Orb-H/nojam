n = int(input())
a = []
b = []
for i in range(n):
    a.append(list(map(int, input().split())))
b.append([a[0][0]])
for i in range(1, n):
    c = [b[i - 1][0] + a[i][0]]
    for j in range(1, i):
        c.append(max(b[i - 1][j - 1], b[i - 1][j]) + a[i][j])
    c.append(b[i - 1][i - 1] + a[i][i])
    b.append(c)
print(max(b[-1]))