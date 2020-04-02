while True:
    s = input()
    if s == '.':
        break
    a = []
    y = True
    for c in s:
        if c == '(':
            a.append(1)
        elif c == '[':
            a.append(2)
        elif c == ')':
            if len(a) == 0 or a[-1] != 1:
                y = False
                break
            a.pop()
        elif c == ']':
            if len(a) == 0 or a[-1] != 2:
                y = False
                break
            a.pop()
    if len(a) != 0:
        y = False
    print('yes' if y else 'no')