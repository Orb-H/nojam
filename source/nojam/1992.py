def f(s, i, j):
    global a
    if s == 1:
        return str(a[i][j])
    else:
        t = s // 2
        r = [f(t, i, j), f(t, i, j + t), f(t, i + t, j), f(t, i + t, j + t)]
        if r[0] == r[1] and r[1] == r[2] and r[2] == r[3] and len(r[0]) == 1:
            return r[0]
        else:
            return '(' + ''.join(r) + ')'


n = int(input())
a = []
for i in range(n):
    a.append(input())
print(f(n, 0, 0))