s = input()
h = 10

for i in range(1, len(s)):
    h += 5 if s[i] == s[i - 1] else 10
print(h)