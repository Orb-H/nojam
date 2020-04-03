def f(s, i, j):
    global a, c
    if s == 1:
        c[a[i][j]] += 1
        return a[i][j]
    else:
        t = s // 3
        r = [f(t, i + m * t, j + n * t) for n in range(3) for m in range(3)]
        s = sum(r)
        if s == 9:
            c[1] -= 8
        elif s == -9:
            c[-1] -= 8
        elif s == 0 and max(r) == 0:
            c[0] -= 8
        return s / 9


n = int(input())
a = []
c = [0, 0, 0]
for i in range(n):
    a.append(list(map(int, input().split())))
f(n, 0, 0)
print(c[-1], c[0], c[1], sep='\n')