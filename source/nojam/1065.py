def h(n):
    if n < 100:
        return True
    if n >= 1000:
        return False
    a, b, c = map(int, str(n))
    return 2 * b == a + c


n = int(input())
c = 0
for i in range(1, n + 1):
    if h(i):
        c += 1
print(c)