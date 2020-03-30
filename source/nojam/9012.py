t = int(input())
for i in range(t):
    s = input()
    l = 0
    for c in s:
        if c == '(':
            l += 1
        elif l == 0:
            l = 1
            break
        else:
            l -= 1
    if l == 0:
        print('YES')
    else:
        print('NO')