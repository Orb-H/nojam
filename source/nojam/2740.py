n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
m, k = map(int, input().split())
b = [list(map(int, input().split())) for _ in range(m)]
r = [[0] * k for _ in range(n)]
for i in range(n):
    for j in range(k):
        for h in range(m):
            r[i][j] += a[i][h] * b[h][j]
for i in range(n):
    print(' '.join(str(x) for x in r[i]))