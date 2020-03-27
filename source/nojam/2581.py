a = [True] * 10001
a[0], a[1] = False, False
for i in range(2, 10001):
    if a[i]:
        for j in range(2, 10000 // i + 1):
            a[i * j] = False
m = int(input())
n = int(input())
s = 0
r = -1
for i in range(m, n + 1):
    if a[i]:
        if r == -1:
            r = i
        s += i
if r == -1:
    print(r)
else:
    print(s)
    print(r)