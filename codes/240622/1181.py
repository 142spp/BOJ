n = int(input())
slist = []
for _ in range(n):
    slist.append(input())

slist = list(set(slist))
slist.sort(key=lambda x: (len(x),x))

for s in slist:
    print(s)