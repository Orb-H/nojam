def g(a, b):
    if b == 0:
        return a
    return g(b, a % b)


a, b = map(int, input().split())
c = g(max(a, b), min(a, b))
print(c)
print(a * b // c)