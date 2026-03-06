input()
n_set = set(list(map(int,input().split())))
input()
m_list = list(map(int,input().split()))
for m in m_list:
    if m in n_set:
        print(1,end=" ")
    else:
        print(0,end=" ")
