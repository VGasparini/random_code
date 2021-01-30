a, b = map(int, input().split())
x = a-b

if x < 0:
    print(0)
elif x == 0:
    print('infinity')
else:
    ans = 0
    for i in range(1, x):
        if x % i == 0:
            if i > b:
                ans += 1
            if x/i > b:
                ans += 1
    # if lim > b and lim * lim == x:
        # ans -= 1
    print(ans)
