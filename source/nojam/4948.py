a = [True] * 246913
a[0] = False
a[1] = False
for i in range(2, 246913):
    if a[i]:
        for j in range(2, 246912 // i + 1):
            a[i * j] = False
while True:
    n = int(input())
    if n == 0:
        break
    c = 0
    for i in range(n + 1, 2 * n + 1):
        if a[i]:
            c += 1
    print(c)