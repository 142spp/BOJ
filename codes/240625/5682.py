import sys
while(True):
    n = sys.stdin.readline().replace('\n','')
    if n == '0' : break
    f = 1
    ans = 0
    l = len(n)
    for i in range(l):
        ans += int(n[l-i-1])*f
        f *= i+2
    print(ans)