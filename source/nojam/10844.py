n = int(input())
a = [[0, 1, 1, 1, 1, 1, 1, 1, 1, 1]]
for i in range(1, n):
    b = a[-1]
    a.append([
        b[1], b[0] + b[2], b[1] + b[3], b[2] + b[4], b[3] + b[5], b[4] + b[6],
        b[5] + b[7], b[6] + b[8], b[7] + b[9], b[8]
    ])
print(sum(a[-1]) % 1000000000)
