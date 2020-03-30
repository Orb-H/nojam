def f(s, l, d):
    global a, n
    if d >= n:
        return abs(
            sum(a[i][j] for i in s for j in s) - sum(a[i][j] for i in l
                                                     for j in l))
    else:
        r = []
        if len(s) < n // 2:
            r.append(f(s + [d], l, d + 1))
        if len(l) < n // 2:
            r.append(f(s, l + [d], d + 1))
        return min(r)


n = int(input())
a = []
for i in range(n):
    a.append(list(map(int, input().split())))
print(f([], [], 0))