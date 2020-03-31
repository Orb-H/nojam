n = int(input())
a = [0] * n
b = []
for i in range(n):
    a[i] = int(input())
b.append([a[0], a[0]])
if n > 1:
    b.append([a[0] + a[1], a[1]])
for i in range(2, n):
    b.append([b[-1][1] + a[i], max(b[-2][0], b[-2][1]) + a[i]])
print(max(b[-1]))