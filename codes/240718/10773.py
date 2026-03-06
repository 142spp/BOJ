k = int(input())

n_list = []
for _ in range(k):
    inp = int(input())
    if inp == 0:
        n_list.pop()
        continue
    n_list.append(inp)
print(sum(n_list))