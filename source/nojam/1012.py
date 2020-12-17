# 1012

t = int(input())

for i in range(t):
    m, n, k = map(int, input().split())
    count = 0
    a = []

    for j in range(n):
        a.append([False] * m)

    for j in range(k):
        x, y = map(int, input().split())
        a[y][x] = True

    for j in range(n):
        for k in range(m):
            if not a[j][k]:
                continue
            count += 1
            q = [(j, k)]
            a[j][k] = False
            while len(q) > 0:
                cur = q[0]
                y = cur[0]
                x = cur[1]
                q = q[1:]
                if y != 0 and a[y - 1][x]:
                    q.append((y - 1, x))
                    a[y - 1][x] = False
                if x != 0 and a[y][x - 1]:
                    q.append((y, x - 1))
                    a[y][x - 1] = False
                if y != n - 1 and a[y + 1][x]:
                    q.append((y + 1, x))
                    a[y + 1][x] = False
                if x != m - 1 and a[y][x + 1]:
                    q.append((y, x + 1))
                    a[y][x + 1] = False
    
    print(count)