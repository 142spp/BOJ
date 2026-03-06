def gcd(n,m):
    if m > n : n,m = m,n
    r = n
    
    while r != 0:
        r = n%m
        n = m
        m = r
    
    return n

n, m = map(int,input().split())
g = gcd(n,m)
print(g)
print(int(n*m/g))

'''
24 18
18 6
6 0
'''