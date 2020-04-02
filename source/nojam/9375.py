t = int(input())
for i in range(t):
    n = int(input())
    d = {}
    for j in range(n):
        s = input().split()[1]
        d[s] = d.get(s, 0) + 1
    r = 1
    for j in d.values():
        r *= j + 1
    print(r - 1)