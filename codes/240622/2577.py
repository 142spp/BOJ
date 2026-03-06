a = int(input())
b = int(input())
c = int(input())

mult : int = a*b*c
nlist = [0]*10
while(mult>0):
    nlist[int(mult%10)] += 1
    mult /= 10
    mult = int(mult)
    
for i in nlist:
    print(i)