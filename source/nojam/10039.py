s = 0
for i in range(5):
    x = int(input())
    s += x if x > 40 else 40
print(s // 5)