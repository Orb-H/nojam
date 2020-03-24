def cycle(n):
    return sum(map(int, list(str(n)))) % 10 + 10 * (n % 10)


n = int(input())
c = 1
m = cycle(n)
while n != m:
    m = cycle(m)
    c += 1
print(c)