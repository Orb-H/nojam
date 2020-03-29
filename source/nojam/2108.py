import sys
n = int(sys.stdin.readline())
a = [0] * 8001
for i in range(n):
    p = int(sys.stdin.readline())
    a[p + 4000] += 1
s = 0  #sum
c = 0  #center
l = -1  #lower
u = 0  #upper
x = 0  #count
for i in range(8001):
    if a[i] > 0:
        s += (i - 4000) * a[i]
        if l == -1:
            l = i
        if u < i:
            u = i
        if x <= n // 2 and x + a[i] > n // 2:
            c = i
        x += a[i]
print(round(s / n))
print(c - 4000)
m = max(a)  #mode
o = a.index(m)  #index of mode
try:
    print(a.index(m, o + 1) - 4000)
except:
    print(o - 4000)
print(u - l)