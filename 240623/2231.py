n = int(input())
flag = False
for i in range(n-100,n):
    s = i
    t = i
    while t > 0:
        s += t%10
        t //= 10 
    if s == n :
        print(i)
        flag = True
        break
    
if flag == False : print(0)


        