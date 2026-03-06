import sys

def quick_sort(l):
    if len(l) <= 1:
        return l
    mid_list = []
    left_list = []
    right_list = []
    pivot = l[int(len(l)/2)]
    for i in l:
        if i == pivot : mid_list.append(i)
        if i <  pivot : left_list.append(i)
        if i >  pivot : right_list.append(i)

    return quick_sort(left_list) + mid_list + quick_sort(right_list)

n = int(input())
nlist = []

for _ in range(n):
    nlist.append(int(sys.stdin.readline()))

slist =quick_sort(nlist)
for s in slist:
    print(s)