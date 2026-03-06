n = int(input())
nlist = list(map(int,input().split()))

max_num = max(nlist)
total = 0
for num in nlist:
    total += (num/max_num)*100

print(total/len(nlist))