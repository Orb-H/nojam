t = int(input())
for i in range(t):
    s = input()
    p = 0
    c = 0
    for x in s:
        c = c + 1 if x == 'O' else 0
        p += c
    print(p)