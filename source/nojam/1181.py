n = int(input())
a = set()
for i in range(n):
    s = input()
    a.add((len(s), s))
a = sorted(a)
for s in a:
    print(s[1])