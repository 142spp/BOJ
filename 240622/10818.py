n = int(input())
nlist = map(int,input().split())

max_n = -1000000
min_n = 1000000

for num in nlist:
    if num > max_n :
        max_n = num
    if num < min_n:
        min_n = num
        
print(f"{min_n} {max_n}")