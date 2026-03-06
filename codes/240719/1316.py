ans = 0
n = int(input())
for _ in range(n):  
    check = [0]*26
    s = input()
    cur = s[0]
    ans += 1
    for c in s:
        if c != cur and check[ord(c)-ord('a')] != 0:
            ans -= 1
            break
        check[ord(c)-ord('a')] += 1
        cur = c
print(ans)