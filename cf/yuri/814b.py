def solve(p, q):
    return sum(p[i] != q[i] for i in range(n)) == 1


n = int(input())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
wa = [0 for i in range(n + 1)]
wb = wa.copy()

for i in a:
    wa[i] += 1
for i in b:
    wb[i] += 1
ta = []
for i in range(1, n + 1):
    if wa[i] == 0:
        sa = i
for i in range(n):
    if wa[a[i]] == 2:
        ta.append(i)

p = a.copy()
p[ta[0]] = sa
if solve(p, b):
    ans = p.copy()
else:
    p = a.copy()
    p[ta[1]] = sa
    if solve(p, b):
        ans = p.copy()
print(*ans)
