n, x = map(int, input().split())
a = list(map(int, input().split()))
for i in range(n):
    print('{0} '.format(a[i]) if a[i] < x else '', end='')