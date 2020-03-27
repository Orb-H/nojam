t = int(input())
for i in range(t):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    d = ((x1 - x2)**2 + (y1 - y2)**2)**0.5
    print(0 if r1 + r2 < d else 1 if r1 + r2 == d else 2 if abs(r1 - r2) < d else (-1 if r1 == r2 else 1) if abs(r1 - r2) == d else 0)