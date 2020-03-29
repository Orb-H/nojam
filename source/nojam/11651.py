n = int(input())
a = []
for i in range(n):
    x, y = map(int, input().split())
    a.append((y, x))
a.sort()
for p in a:
    print('{0} {1}'.format(p[1], p[0]))