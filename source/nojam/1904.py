n = int(input())
a = [0, 1]
while len(a) <= n + 1:
    a.append((a[-1] + a[-2]) % 15746)
print(a[-1])