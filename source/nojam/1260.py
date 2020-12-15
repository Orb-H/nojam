def dfs(v):
    global visited, path, n, a
    path.append(v)
    visited[v] = True
    for i in range(n + 1):
        if a[v][i] and not visited[i]:
            dfs(i)

n, m, v = map(int, input().split())
a = []
for i in range(n + 1):
    a.append([False] * (n + 1))

for i in range(m):
    x, y = map(int, input().split())
    a[x][y] = True
    a[y][x] = True

visited = [False] * (n + 1)
path = []
dfs(v)
print(" ".join([str(x) for x in path]))

q = [v]
visited = [False] * (n + 1)
path = []
while len(q) > 0:
    cur = q[0]
    q = q[1:]
    if visited[cur]:
        continue
    path.append(cur)
    visited[cur] = True
    for i in range(n + 1):
        if a[cur][i]:
            q.append(i)
print(" ".join([str(x) for x in path]))