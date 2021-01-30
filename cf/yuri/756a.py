n = int(input())
p = [int(i) for i in input().split()]
zeros = [int(i) for i in input().split()]

ans = 0
if sum(zeros) % 2 == 0:
    ans += 1

visited = [False] * n

ciclos = 0
for i in range(n):
    if not visited[i]:
        ciclos += 1
    j = i
    while not visited[j]:
        visited[j] = True
        j = p[j] - 1

if ciclos == 1:
    ans += 0
else:
    ans += ciclos

print(ans)
