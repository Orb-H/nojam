x, y = map(int, input().split())
a, b = map(int, input().split())
c, d = map(int, input().split())
print(x ^ a ^ c, y ^ b ^ d)