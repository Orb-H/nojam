n, m = map(int, input().split())
b = list(map(int, input().split()))
a = [i + 1 for i in range(n)]
r = 0
for i in range(m):
    c = 0
    d = a.index(b[i])
    if d <= n // 2:
        c = d
        for j in range(c):
            a.append(a.pop(0))
    else:
        c = n - d
        for j in range(c):
            a.insert(0, a.pop())
    r += c
    a.pop(0)
    n -= 1
print(r)