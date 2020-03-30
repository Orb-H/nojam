def l(a, n, m):
    if len(a) == m:
        print(' '.join(str(x) for x in a))
    else:
        for i in range(n):
            if not i + 1 in a:
                l(a + [i + 1], n, m)


n, m = map(int, input().split())
l([], n, m)