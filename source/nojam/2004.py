n, m = map(int, input().split())
l = n - m
nn, mm, ll = n, m, l
r = 0
s = 0
while n > 0:
    n //= 5
    r += n
while nn > 0:
    nn //= 2
    s += nn
while m > 0:
    m //= 5
    r -= m
while mm > 0:
    mm //= 2
    s -= mm
while l > 0:
    l //= 5
    r -= l
while ll > 0:
    ll //= 2
    s -= ll
print(min(r, s))