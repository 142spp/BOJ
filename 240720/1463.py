def dp(n,table):
    if table[n] != 0:
        return table[n]
    if n == 1:
        return 0
    a1,a2,a3 = n,n,n
    if n%3 == 0 : 
        a1 = dp(n//3,table)
    if n%2 == 0 : 
        a2 = dp(n//2,table)
    if n%3 !=0 or n%2 !=0:
        a3 = dp(n-1,table)
    table[n] = min(a1,a2,a3)+1
    return table[n]

n = int(input())
table = [0]*(n+1)

print(dp(n,table))