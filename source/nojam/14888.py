def f(a, o, d, m):
    if d >= len(a):
        return [m, m]
    else:
        r = []
        if o[0] > 0:
            o[0] -= 1
            r.append(f(a, o, d + 1, m + a[d]))
            o[0] += 1
        if o[1] > 0:
            o[1] -= 1
            r.append(f(a, o, d + 1, m - a[d]))
            o[1] += 1
        if o[2] > 0:
            o[2] -= 1
            r.append(f(a, o, d + 1, m * a[d]))
            o[2] += 1
        if o[3] > 0:
            o[3] -= 1
            if m >= 0:
                r.append(f(a, o, d + 1, m // a[d]))
            else:
                r.append(f(a, o, d + 1, -((-m) // a[d])))
            o[3] += 1
        return [max(x[0] for x in r), min(x[1] for x in r)]


n = int(input())
a = list(map(int, input().split()))
o = list(map(int, input().split()))
x, n = f(a[1:], o, 0, a[0])
print(x)
print(n)