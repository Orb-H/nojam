import sys
sys.stdin.readline()
a = sorted(map(int, sys.stdin.readline().rstrip().split()))
sys.stdin.readline()
b = list(map(int, sys.stdin.readline().rstrip().split()))
for x in b:
    s = 0
    e = len(a)
    m = (s + e) // 2
    while True:
        if a[m] == x:
            print(1)
            break
        else:
            if e - s == 1:
                print(0)
                break
            elif a[m] < x:
                s = m
                m = (s + e) // 2
            else:
                e = m
                m = (s + e) // 2