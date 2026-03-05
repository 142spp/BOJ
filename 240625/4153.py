while True:
    a,b,c = map(int,input().split())
    if a+b+c == 0 : break
    l = [a,b,c]
    m = max(l)
    ans = False
    for x in l:
        for y in l:
            if x==y : continue
            if x**2 + y**2 == m**2:
                ans = True
    if ans :
        print ('right')
    else :
        print ('wrong')