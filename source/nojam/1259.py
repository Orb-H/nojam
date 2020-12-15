while True:
    x = input()
    n = len(x)
    f = True

    if x == '0':
        break

    for i in range(n // 2):
        if x[i] != x[n - i - 1]:
            f = False
            break
  
    if f:
        print('yes')
    else:
        print('no')