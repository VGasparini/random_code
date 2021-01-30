n, x = [int(i) for i in input().split()]
aux = 0
for _ in range(n):
    a, b = [int(i) for i in input().split()]
    if (aux >= a and b > aux and b != a):
        aux = b
if aux >= x:
    print("YES")
else:
    print("NO")
