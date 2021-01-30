import sys


def conv(letra):
    return ord(letra)-ord('A')


sys.stdin = open('input.txt', 'r')
sys.stdout = open('output.txt', 'w')

s = [conv(i) for i in input()]
t = [conv(i) for i in input()]

aux = [s.count(i) for i in range(26)]
lista_cont = [aux[i]-t.count(i) for i in range(26)]
# print(lista_cont, 'oi')

p, r = [], 0

for i in range(25, -1, -1):
    if lista_cont[i] < 0:
        # print(p, 'oieei')
        p += [i] * -lista_cont[i]
        r -= lista_cont[i]

cont = 0
for x in s:
    if lista_cont[x] > 0 and (p[-1] < x or aux[x] == lista_cont[x]):
        lista_cont[x] -= 1
        s[cont] = p.pop()
    aux[x] -= 1
    cont += 1

print(r)
ans = ''
for i in s:
    ans += chr(i+ord('A'))
print(ans)
