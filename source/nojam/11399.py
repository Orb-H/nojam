n = int(input())
a = list(map(int, input().split()))
a.sort()
c = 0
s = 0
for i in range(n):
    c += a[i]
    s += c
print(s)