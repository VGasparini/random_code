m = int(input())
for i in range(m):
	n,x,t = list(map(int,input().split()))
	cruzar_todos = 2*n*t
	esperar_esquerda = cruzar_todos + max(cruzar_todos, t+t+x)
	esperar_direita = cruzar_todos + max(cruzar_todos, x) + t
	print(min(esperar_esquerda, esperar_direita))
