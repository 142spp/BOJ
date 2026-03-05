n,b = map(str,input().split())
b = int(b)

ans = 0
for c in n:
    ans *= b
    if ord(c) >= ord('A') and ord(c) <= ord('Z'):
        ans += ord(c)-ord('A')+10
    else:
        ans += int(c)
    
print(ans)