n, m = [int(i) for i in input().split()]
lista = [int(i)-1 for i in input().split()]
aux = [0] * n

for i in range(m):
    for j in range(lista[i], n):
        if not aux[j]:
            aux[j] = lista[i]+1

print(*aux)
