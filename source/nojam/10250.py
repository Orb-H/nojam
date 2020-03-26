t = int(input())
for i in range(t):
    h, w, n = map(int, input().split())
    print('{0}{1:02}'.format((n - 1) % h + 1, (n - 1) // h + 1))