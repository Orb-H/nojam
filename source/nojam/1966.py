t = int(input())
for i in range(t):
    n, m = map(int, input().split())
    p = list(map(int, input().split()))
    x = max(p)
    while True:
        if x == p[0]:
            p.pop(0)
            if m == 0:
                print(n - len(p))
                break
            x = max(p)
        else:
            p.append(p.pop(0))
        m = (m - 1) % len(p)