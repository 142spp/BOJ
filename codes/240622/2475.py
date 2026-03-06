nlist = map(int,input().split())
sum = 0
for n in nlist:
    sum += n*n
print(sum%10)