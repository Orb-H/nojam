n = int(input())
a = []
for i in range(n):
    a.append(input().split())
a.sort(key=lambda x: int(x[0]))
for p in a:
    print('{0} {1}'.format(p[0], p[1]))