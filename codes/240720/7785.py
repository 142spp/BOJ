n = int(input())
n_set = set()
for _ in range(n):
    name, status = map(str,input().split())
    if status == 'enter':
        n_set.add(name)
    elif status == 'leave':
        n_set.remove(name)
n_list = sorted(list(n_set),reverse=True)
for e in n_list:
    print(e)