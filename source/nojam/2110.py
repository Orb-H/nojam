n, c = map(int, input().split())
a = [int(input()) for _ in range(n)]
a.sort()
s = 1
e = (max(a) - min(a)) // (c - 1) + 1
while s < e - 1:
    m = (s + e) // 2
    i = 0
    d = a[i]
    v = 1
    while i < n:
        if a[i] >= d + m:
            d = a[i]
            v += 1
        i += 1
    if v < c:
        e = m
    else:
        s = m
print(s)