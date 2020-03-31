n = int(input())
a = [0] * n
b = []
for i in range(n):
    a[i] = int(input())
b.append([a[0], a[0], a[0]])
if n > 1:
    b.append([a[0] + a[1], a[1], a[1]])
if n > 2:
    b.append([a[1] + a[2], a[0] + a[2], a[2]])
for i in range(3, n):
    b.append(
        [max(b[-1][1], b[-1][2]) + a[i],
         max(b[-2]) + a[i],
         max(b[-3]) + a[i]])
if n > 1:
    print(max(b[-2] + b[-1]))
else:
    print(max(b[-1]))