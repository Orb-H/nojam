def f(n):
    global a
    if a[n] != -1:
        return a[n]
    else:
        x = f(n - 1) + f(n - 2)
        a[n] = x
        return x


t = int(input())
a = [-1] * 41
a[0] = 0
a[1] = 1
for i in range(t):
    n = int(input())
    if n == 0:
        print('1 0')
    else:
        print('{} {}'.format(f(n - 1), f(n)))