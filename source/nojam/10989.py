import sys
n = int(sys.stdin.readline())
a = [0] * 10001
for i in range(n):
    a[int(sys.stdin.readline())] += 1
for i in range(10001):
    if a[i] > 0:
        print('\n'.join([str(i)] * a[i]))