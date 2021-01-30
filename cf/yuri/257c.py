from math import pi, atan2

n = int(input())
ang = []
for _ in range(n):
    x, y = [int(i) for i in input().split()]
    ang.append(atan2(x, y))
ang.sort()
ans = ang[0] + 2*pi - ang[-1]
for i in range(1, n):
    ans = max(ans, ang[i] - ang[i-1])
print("{:.10f}".format(360 - (ans/pi*180)))
