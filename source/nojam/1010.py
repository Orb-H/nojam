t = int(input())

for i in range(t):
    m, n = map(int, input().split())
    m = min(m, n - m)
    r = 1

    for i in range(1, m + 1):
        r *= n - m + i
        r //= i
    print(r)