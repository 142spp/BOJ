from math import ceil
n = int(input())
for _ in range(n):
    h,w,m = map(int,input().split())
    f = m%h
    if f == 0 : f = h
    print(f'{f}{ceil(m/h):02d}')