n, m = map(int,input().split())

bucket = [x for x in range(n+1)]
for _ in range(m):
    s,e = map(int,input().split())
    t_list = bucket[s:e+1]
    t_list.reverse()
    for x in range(s,e+1):
        bucket[x] = t_list[x-s]

for i in range(1,n+1):
    print(bucket[i],end=" ")