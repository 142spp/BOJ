import sys

merged_list = []
def merge_sort(l):
    if len(l) == 1: return l
    
    mid = len(l)//2
    left = merge_sort(l[mid:])
    right = merge_sort(l[:mid])

    

n = int(input())
nlist = []

for _ in range(n):
    nlist.append(int(sys.stdin.readline()))

slist =merge_sort(nlist)
for s in slist:
    print(s)