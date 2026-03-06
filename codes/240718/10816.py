n = int(input())
n_list = list(map(int,input().split()))

n_dict = {}
for e in n_list:
    if e in n_dict:
        n_dict[e] += 1
    else:
        n_dict[e] = 1

m = int(input())
m_list = list(map(int,input().split()))

for e in m_list:
    if e in n_dict:
        print(n_dict[e],end=" ")
    else :
        print(0,end=" ")