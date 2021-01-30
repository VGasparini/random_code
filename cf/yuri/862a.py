n, x = [int(i) for i in input().split()]
lista = [int(i) for i in input().split()]
 
aux = [0 for i in range(200)]
 
for i in lista: aux[i] += 1
 
ans = 0
for i in range(x):
    if aux[i] == 0:
        ans += 1
        
if aux[x] == 1: ans += 1
print(ans)
