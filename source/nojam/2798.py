n, m = map(int, input().split())
c = list(map(int, input().split()))
r = -1
for i in range(0, n - 2):
    for j in range(i + 1, n - 1):
        for k in range(j + 1, n):
            s = c[i] + c[j] + c[k]
            if c[i] + c[j] + c[k] <= m:
                r = max(r, s)
print(r)