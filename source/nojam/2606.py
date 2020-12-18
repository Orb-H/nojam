from collections import deque

n = int(input())
m = int(input())
a = []
res = 0
visited = [False] * (n + 1)

for i in range(n + 1):
    a.append([False] * (n + 1))

for j in range(m):
    x, y = map(int, input().split())
    a[x][y] = True
    a[y][x] = True

q = deque([1])
visited[1] = True
while len(q) > 0:
    cur = q.popleft()
    for i in range(1, n + 1):
        if not visited[i] and a[cur][i]:
            q.append(i)
            visited[i] = True
            res += 1
print(res)