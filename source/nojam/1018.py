n, m = map(int, input().split())
a = []
for i in range(n):
    a.append(input())
b = []
for i in range(n):
    b.append([0] * m)
for i in range(n):
    for j in range(m):
        b[i][j] = 1 if ((i + j) % 2 == 1 and a[i][j] == 'W') or (
            (i + j) % 2 == 0 and a[i][j] == 'B') else 0
c = 0
r = 64
for i in range(n - 7):
    for j in range(m - 7):
        c = sum(b[i + x][j + y] for x in range(8) for y in range(8))
        r = min(r, c, 64 - c)
print(r)