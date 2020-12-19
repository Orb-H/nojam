n = int(input())

if n <= 2:
    print(2 * n - 1)
else:
    a = [0] * n
    a[0] = 1
    a[1] = 3
    for i in range(2, n):
        a[i] = (a[i - 1] + 2 * a[i - 2]) % 10007
    print(a[n - 1])