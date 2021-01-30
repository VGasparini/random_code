n = int(input())
lista = [int(i) for i in input().split() if int(i) <= n]
print(n - len(set(lista)))
