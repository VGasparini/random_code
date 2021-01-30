s = input()
ans = -1
l, r = 0, len(s)-1
while l < r:
    ls = s[l]
    rs = s[r]
    if ls != rs:
        ans = 0
        break

    llen = 0
    while l < len(s) and s[l] == ls:
        l += 1
        llen += 1
    rlen = 0
    while r >= 0 and s[r] == rs:
        r -= 1
        rlen += 1
    if llen + rlen < 3:
        ans = 0
        break

if l-r-1 >= 2:
    print(str(l-r))
else:
    print(str(0))
