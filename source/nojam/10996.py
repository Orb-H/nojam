n = int(input())
for i in range(2 * n):
    for j in range(n):
        print('*' if (i + j) % 2 == 0 else ' ', end='')
    print()