def f(s, x, y):
    global a, c
    if s == 1:
        c[a[x][y]] += 1
        return a[x][y]
    else:
        t = s // 2
        r = [f(t, x, y), f(t, x + t, y), f(t, x, y + t), f(t, x + t, y + t)]
        s = sum(r)
        if s == 4:
            c[1] -= 3
        elif s == 0:
            c[0] -= 3
        return s / 4


n = int(input())
a = []
c = [0, 0]
for i in range(n):
    a.append(list(map(int, input().split())))
f(n, 0, 0)
print(c[0])
print(c[1])