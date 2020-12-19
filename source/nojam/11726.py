n = int(input())

if n <= 2:
    print(n)
else:
    a = [0] * n
    a[0] = 1
    a[1] = 2
    for i in range(2, n):
        a[i] = (a[i - 1] + a[i - 2]) % 10007
    print(a[n - 1])