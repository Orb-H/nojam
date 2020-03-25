n = int(input())
for i in range(n):
    s = input()
    c = [False] * 26
    while len(s) > 0:
        if c[ord(s[0]) - 97]:
            n -= 1
            break
        c[ord(s[0]) - 97] = True
        while len(s) > 1 and s[0] == s[1]:
            s = s[1:]
        s = s[1:]
print(n)