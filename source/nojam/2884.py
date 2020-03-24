h, m = map(int, input().split())
h = h if m >= 45 else (h + 23) % 24
m = (m + 15) % 60
print(h, m)