import sys
t = int(sys.stdin.readline().rstrip())
for i in range(t):
    print(sum(map(int, sys.stdin.readline().rstrip().split())))