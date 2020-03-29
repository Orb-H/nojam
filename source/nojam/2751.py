import sys
n = int(sys.stdin.readline())
a = [0] * n
for i in range(n):
    a[i] = int(sys.stdin.readline())
a.sort()
for i in range(n):
    print(a[i])