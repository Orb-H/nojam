l = int(input())
s = input()
n = len(s)
h = 0

for i in range(n):
    h = ((h * 31) + (ord(s[n - i - 1]) - ord('a') + 1)) % 1234567891
print(h)