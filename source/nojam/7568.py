n = int(input())
a = []
b = [1] * n
for i in range(n):
    a.append(list(map(int, input().split())))
for i in range(n):
    for j in range(n):
        if a[i][0] < a[j][0] and a[i][1] < a[j][1]:
            b[i] += 1
print(' '.join(str(b[i]) for i in range(n)))