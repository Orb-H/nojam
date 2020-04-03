def p(a, b, c):
    if b == 1:
        return a % c
    h = p(a, b // 2, c)
    return (h * h * (a if b % 2 == 1 else 1)) % c


a, b, c = map(int, input().split())
print(p(a, b, c))