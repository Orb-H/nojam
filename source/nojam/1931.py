n = int(input())
a = [0] * n
for i in range(n):
    s, e = map(int, input().split())
    a[i] = [e, s]
a.sort()
c = 1
t = a[0][0]
for i in range(1, n):
    if a[i][1] >= t:
        c += 1
        t = a[i][0]
print(c)