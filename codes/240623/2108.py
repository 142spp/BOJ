m = int(input())
nlist = []
ndict  = {}
for _ in range(m):
    n= int(input())
    nlist.append(n)
    if n in ndict.keys():
        ndict[n] += 1
    else:
        ndict[n] = 1
nlist.sort()
slist = sorted(ndict.items(),key=lambda x : x[0])
slist = sorted(dict(slist).items(),key=lambda x : x[1],reverse=True)
print(round(sum(nlist)/len(nlist)))
print(nlist[int((len(nlist)-1)/2)])
try:
    if slist[0][1] == slist[1][1]:
        print(slist[1][0])
    else: print(slist[0][0])
except:
    print(slist[0][0])
print(nlist[-1]-nlist[0])
