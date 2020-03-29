n = int(input())
a = []
for i in range(n):
    a.append(tuple(map(int, input().split())))
a.sort()
for p in a:
    print('{0} {1}'.format(p[0], p[1]))