n = int(input())
a = [1] * (n + 1)
a[0] = 0
a[1] = 0
for i in range(2, n + 1):
    a[i] = 1 + a[i - 1]
    if i % 2 == 0:
        a[i] = min(a[i], 1 + a[i // 2])
    if i % 3 == 0:
        a[i] = min(a[i], 1 + a[i // 3])
print(a[-1])