n = int(input())
ans = [0,0,0,0,0,0,0]
for i in range(n):
    s = input()
    for j in range(7):
        ans[j]+=int(s[j])
print(max(ans))
