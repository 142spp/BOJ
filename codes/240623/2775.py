t = int(input())
for _ in range(t):
    k = int(input())
    n = int(input())
    ll = [[j for j in range(n+1)] for i in range(k+1)]
    for i in range(1,k+1) :
        for j in range(1,n+1):
            ll[i][j] = ll[i-1][j] + ll[i][j-1]

    print(ll[k][n])