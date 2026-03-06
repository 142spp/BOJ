n = int(input())
p = list(map(int,input().split()))
s = list(map(int,input().split()))

c = 0
for i in range(len(p)):
    if s[i] >= p[i]:
        c += 1
print(c)