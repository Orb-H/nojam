t = int(input())
for i in range(t):
    r, s = input().split()
    r = int(r)
    print(''.join(map(lambda x: x * r, s)))