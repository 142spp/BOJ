total = int(input())
n = int(input())
s = 0
for _ in range(n):
    a,b = map(int,input().split())
    s += a*b
if s == total:
    print("Yes")
else:
    print("No")