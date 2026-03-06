from math import ceil
N = int(input())
tlist = map(int,input().split())
t, p = map(int,input().split())

ans_t, ans_p1, ans_p2 = 0,0,0

for size in tlist:
    ans_t = ans_t + ceil(size/t)
    
ans_p1 = N//p
ans_p2 = N%p

print(ans_t,'\n',ans_p1,'\n',ans_p2,sep="")
