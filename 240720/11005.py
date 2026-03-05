table = [chr(x) for x in range(ord('0'),ord('9')+1)]
table += [chr(x) for x in range(ord('A'),ord('Z')+1)]

n ,b = map(int,input().split())
tb = b
while n >= tb : tb *= b
tb //= b

ans = ''
while n >= 0 and tb > 0:
    ans += table[n//tb]
    n %= tb
    tb //= b
    
print(ans)