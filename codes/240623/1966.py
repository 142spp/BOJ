tc = int(input())
for _ in range(tc):
    n,m = map(int,input().split())
    pq = list(map(int,input().split()))
    
    cur, cnt = 0,0
    while(True):
        pmax = max(pq)
        if pq[cur] == pmax:
            if cur == m:
                print(cnt+1)
                break
            pq[cur] = -1
            cnt += 1
            
        cur += 1
        if cur >= len(pq):
            cur = 0
    