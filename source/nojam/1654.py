def f(s, e):
    if e - s == 1:
        return s
    global a, n
    m = (s + e) // 2
    r = 0
    for l in a:
        r += l // m
    if r < n:
        return f(s, m)
    elif r >= n:
        return f(m, e)


k, n = map(int, input().split())
a = [int(input()) for _ in range(k)]
print(f(0,max(a)+1))