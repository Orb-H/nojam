def hanoi(n, s, d):
    if n == 1:
        print('{0} {1}'.format(s, d))
    else:
        x = s ^ d
        hanoi(n - 1, s, x)
        print('{0} {1}'.format(s, d))
        hanoi(n - 1, x, d)


n = int(input())
print(2**n - 1)
hanoi(n, 1, 3)