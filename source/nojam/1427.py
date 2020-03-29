n = int(input())
a = [0] * 10
while n > 0:
    a[n % 10] += 1
    n //= 10
for i in range(9, -1, -1):
    if a[i] > 0:
        print(''.join(str(i) * a[i]), end='')