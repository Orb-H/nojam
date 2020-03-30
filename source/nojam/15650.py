def l(a, n, m):
    if len(a) == m:
        print(' '.join(str(x) for x in a))
    else:
        for i in range(a[-1], n):
            l(a + [i + 1], n, m)


n, m = map(int, input().split())
for i in range(n):
    l([i + 1], n, m)