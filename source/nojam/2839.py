n = int(input())
c = 0
while n >= 0 and n % 5 != 0:
    n -= 3
    c += 1
if n < 0:
    print(-1)
else:
    print(c + n // 5)