n = int(input())
found = False
for i in range(1, n):
    c = i + sum(map(int, str(i)))
    if c == n:
        print(i)
        found = True
        break
if not found:
    print(0)