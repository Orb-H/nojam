t = int(input())
for i in range(t):
    p = input()
    n = int(input())
    a = input().strip('[]').split(',')
    if len(a[0]) == 0:
        x = []
    else:
        x = list(map(int, a))
    r = False
    b = True
    for c in p:
        if c == 'R':
            r = not r
        else:
            try:
                x.pop(-1 if r else 0)
            except:
                b = False
    if b:
        print('[' + ','.join(str(y) for y in (reversed(x) if r else x)) + ']')
    else:
        print('error')