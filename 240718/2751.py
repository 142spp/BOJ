n = int(input())
n_list = []
for _ in range(n):
    n_list.append(int(input()))
    
s_list = sorted(n_list)
for e in s_list:
    print(e)