a = ['ABC', 'DEF', 'GHI', 'JKL', 'MNO', 'PQRS', 'TUV', 'WXYZ']
s = input()
m = 0
for c in s:
    for i in range(len(a)):
        if c in a[i]:
            m += i + 3
print(m)