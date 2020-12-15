n, r, c = map(int, input().split())
x = 0

for i in range(n):
    dr = 2 << (2 * i)
    dc = 1 << (2 * i)

    if r & (1 << i):
        x += dr
    if c & (1 << i):
        x += dc
print(x)