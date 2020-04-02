n = int(input())
a = []
r = []
s = [0]
p = True
for i in range(n):
    a.append(int(input()))
j = 1
i = 0
while i < n:
    if s[-1] < a[i]:
        s.append(j)
        j += 1
        r.append('+')
    elif s[-1] == a[i]:
        s.pop()
        i += 1
        r.append('-')
    else:
        p = False
        break
if p:
    for t in r:
        print(t)
else:
    print('NO')