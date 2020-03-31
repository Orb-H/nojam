n = int(input())
a = []
for i in range(n):
    a.append(list(map(int, input().split())))
a.sort()
b = [1] * n
for i in range(1, n):
    for j in range(0, i):
        if a[i][1] > a[j][1]:
            b[i] = max(b[i], b[j] + 1)
print(len(b) - max(b))