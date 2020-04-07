n, m, b = map(int, input().split())
a = [0] * 257
s = 256
e = 0
for _ in range(n):
    for i in map(int, input().split()):
        a[i] += 1
        if s > i:
            s = i
        if e < i:
            e = i
t = 512 * n * m
r = 0
for h in range(s, e + 1):
    bu = 0
    tu = 0
    for i in range(257):
        if i < h:
            bu += a[i] * (h - i)
            tu += a[i] * (h - i)
        elif i > h:
            bu -= a[i] * (i - h)
            tu += 2 * a[i] * (i - h)
    if bu > b:
        continue
    if tu <= t:
        t = tu
        r = h
print('{0} {1}'.format(t, r))