import math
n = int(input())
print(math.ceil((math.sqrt(8 * ((n + 4) // 6) + 1) - 1) / 2 + 1) if n > 1 else 1)