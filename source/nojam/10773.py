k = int(input())
a = []
for i in range(k):
    c = int(input())
    if c > 0:
        a.append(c)
    else:
        a.pop()
print(sum(a))