n, m = map(int,input().split())
nlist = list(map(int,input().split()))

s = len(nlist)
mini = m
for i in range(s):
    for j in range(i+1,s):
        for k in range(j+1,s):
            val = m-(nlist[i] + nlist[j] + nlist[k])
            if val >= 0 and val < mini:
                mini = val

print(m-mini)