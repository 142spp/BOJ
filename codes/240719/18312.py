h,m,s = 0,0,0
n, k = map(int,input().split())

ans = 0
while h!=n+1 :
    hms = f'{str(h):>02}+{str(m):>02}+{str(s):>02}'
    if str(k) in hms: ans+= 1
    s += 1
    
    if s >= 60:
        s -= 60
        m += 1
    if m >= 60:
        m -= 60
        h += 1
    
print(ans)