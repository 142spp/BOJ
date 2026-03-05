n,m = map(int,input().split())
p_n = {}
p_s = {}

for i in range(n):
    s = input()
    p_n[i+1] = s
    p_s[s] = i+1
for _ in range(m):
    s = input()
    if s.isdigit():
        print(p_n[int(s)])
    else:
        print(p_s[s])