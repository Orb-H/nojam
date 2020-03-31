n = int(input())
a = []
b = []
for i in range(n):
    a.append(list(map(int, input().split())))
b.append(a[0])
for i in range(1, n):
    b.append([
        min(b[i - 1][1], b[i - 1][2]) + a[i][0],
        min(b[i - 1][0], b[i - 1][2]) + a[i][1],
        min(b[i - 1][0], b[i - 1][1]) + a[i][2]
    ])
print(min(b[-1]))