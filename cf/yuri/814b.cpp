read = lambda: map(int, input().split())
n = int(input())
a = list(read())
b = list(read())
wa = [0] * (n + 1)
wb = [0] * (n + 1)
for i in a: wa[i] += 1
for i in b: wb[i] += 1
ta = []
for i in range(1, n + 1):
    if wa[i] == 0:
        sa = i
for i in range(n):
    if wa[a[i]] == 2:
        ta.append(i)
f = lambda p, q: sum(p[i] != q[i] for i in range(n)) == 1
p = a[:]
p[ta[0]] = sa
if f(p, b): ans = p[:]
else:
    p = a[:]
    p[ta[1]] = sa
    if f(p, b): ans = p[:]
print(*ans)