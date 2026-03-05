n = int(input())
n_list = list(map(int,input().split()))
v = int(input())
s = 0
for e in n_list:
    if e == v:
        s+= 1
print(s)