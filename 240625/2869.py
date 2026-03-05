from math import ceil

a,b,v = map(int,input().split())

ans = ceil(v/(a-b))
if (v-b)%a > 0:
    ans -= 1
print(ans)