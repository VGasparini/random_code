from math import ceil, floor
 
def solve(n):
    return n * (n+1)
 
a = int(input())
b = int(input())
 
n = abs(a-b)/2
 
print((solve(ceil(n)) + solve(floor(n))) // 2)
