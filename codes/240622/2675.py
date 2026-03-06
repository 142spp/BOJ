n = int(input())
for _ in range(n):
    r, s = map(str,input().split())
    r = int(r)
    for c in s:
        if c == '\n' : continue
        print(f"{c*r}",end="")
    print("")        