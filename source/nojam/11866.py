n, k = map(int, input().split())
a = [i + 1 for i in range(n)]
j = 0
b = []
for i in range(n - 1):
    j = (j + k - 1) % len(a)
    b.append(a.pop(j))
b.append(a.pop(0))
print('<', end='')
print(', '.join(str(x) for x in b), end='')
print('>')