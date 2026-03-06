import sys

n = int(input())
x_list = list(map(int,sys.stdin.readline().rstrip().split()))

s_list = sorted(list(set(x_list)))
s_dict = {}
for i in range(len(s_list)):
    s_dict[s_list[i]] = i

for x in x_list:
    print(s_dict[x],end=" ")
    