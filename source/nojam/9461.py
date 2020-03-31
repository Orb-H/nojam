def f(n):
    global a
    if len(a) > n:
        return a[n]
    else:
        a.append(f(n - 1) + f(n - 5))
        return a[n]


t = int(input())
a = [0, 1, 1, 1, 2, 2]
for i in range(t):
    n = int(input())
    print(f(n))