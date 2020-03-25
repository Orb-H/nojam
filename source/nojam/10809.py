s = input()
a = [-1] * 26
for i in range(len(s)):
    d = ord(s[i]) - 97
    if a[d] == -1:
        a[d] = i
print(' '.join(map(str, a)))