def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)
    

t = int(input())

for i in range(t):
    a, b = map(int, input().split())
    print(a * b // gcd(max(a, b), min(a, b)))