n = int(input())
a = list(map(int, input().split()))
b = [1] * n
for i in range(1, n):
    for j in range(0, i):
        if a[i] > a[j]:
            b[i] = max(b[j] + 1, b[i])
print(max(b))