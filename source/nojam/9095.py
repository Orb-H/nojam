n = int(input())

a = [1] * 11
a[1] = 1
a[2] = 2

for i in range(3, 11):
    a[i] = a[i - 1] + a[i - 2] + a[i - 3]

for i in range(n):
    print(a[int(input())])