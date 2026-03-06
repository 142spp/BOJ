n,m = map(int,input().split())
no_hear = set()
no_look = set()

for _ in range(n):
    no_hear.add(input())
for _ in range(m):
    no_look.add(input())

no_two = no_hear.intersection(no_look)
no_list = sorted(list(no_two))

print(len(no_list))
for e in no_list:
    print(e)