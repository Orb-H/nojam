t = int(input())
for i in range(t):
    x = list(map(int, input().split()))
    del x[0]
    a = sum(x) / len(x)
    print('{0:.3F}%'.format(len(list(filter(lambda y: y > a, x))) / len(x) * 100))