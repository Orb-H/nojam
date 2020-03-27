while True:
    a, b, c = sorted(map(int, input().split()))
    if a + b + c == 0:
        break
    print('right' if a**2 + b**2 == c**2 else 'wrong')