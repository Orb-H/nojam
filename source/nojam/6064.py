def g(a, b):
    if b == 0:
        return a
    if a > b:
        return g(b, a % b)
    else:
        return g(a, b % a)


t = int(input())
for i in range(t):
    m, n, x, y = map(int, input().split())
    c = g(m, n)
    if (x - y) % c != 0:
        print(-1)
        continue
    r = 0
    if n < m:
        x = (x - (y - 1)) % m
        r += y
        y = 1
        while x % m != 1:
            x = (x - n) % m
            r += n
    else:
        y = (y - (x - 1)) % n
        r += x
        x = 1
        while y % n != 1:
            y = (y - m) % n
            r += m
    print(r)