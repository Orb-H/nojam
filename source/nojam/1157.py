s = input()
a = [0] * 26
for c in s:
    a[ord(c) % 32 - 1] += 1
if a.index(max(a)) + list(reversed(a)).index(max(a)) != 25:
    print('?')
else:
    print(chr(a.index(max(a)) + 65))