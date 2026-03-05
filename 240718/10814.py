n = int(input())

mem_list = []
for _ in range(n):
    age , name = map(str,input().split())
    mem_list.append((int(age),name))
s_list = sorted(mem_list,key = lambda x: x[0])

for e in s_list:
    print(e[0], e[1])