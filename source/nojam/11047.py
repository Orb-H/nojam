n, k = map(int, input().split())
a = [0] * n
for i in range(n):
    a[i] = int(input())
c = 0
for b in reversed(a):
    if k >= b:
        d = k // b
        c += d
        k -= d * b
print(c)