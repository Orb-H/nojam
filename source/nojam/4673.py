a = [True] * 10001


def d(n):
    n = n + sum(map(int, str(n)))
    while n <= 10000:
        a[n] = False
        n = n + sum(map(int, str(n)))


for i in range(1, 10001):
    if a[i]:
        d(i)
for i in range(1, 10001):
    if a[i]:
        print(i)