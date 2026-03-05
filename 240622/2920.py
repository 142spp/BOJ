nlist = list(map(int,input().split()))

if nlist == sorted(nlist):
    print("ascending")
elif nlist == sorted(nlist,reverse=True):
    print("descending")
else:
    print("mixed")