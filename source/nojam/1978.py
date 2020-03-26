a = [True] * 1001
a[0], a[1] = False, False
for i in range(2, 1001):
    for j in range(2, 1000 // i + 1):
        a[i * j] = False
input()
s = map(int, input().split())
c = 0
for i in s:
    c += 1 if a[i] else 0
print(c)