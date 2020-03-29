n, k = map(int, input().split())
r = 1
for i in range(k):
    r *= (n - i)
for i in range(k):
    r //= i + 1
print(r)