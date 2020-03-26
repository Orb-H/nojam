t = int(input())
for i in range(t):
    k = int(input())
    n = int(input())
    r = 1
    for j in range(k + 1):
        r = r * (n + j) // (j + 1)
    print(r)