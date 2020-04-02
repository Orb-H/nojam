def g(a, b):
    if a < b:
        a, b = b, a
    while b != 0:
        a, b = b, a % b
    return a


n = int(input())
a = list(map(int, input().split()))
for i in range(1, n):
    c = g(a[0], a[i])
    print('{0}/{1}'.format(a[0] // c, a[i] // c))