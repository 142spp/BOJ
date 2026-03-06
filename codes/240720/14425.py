n ,m = map(int,input().split())
s = set()
for _ in range(n):
    s.add(input())
total = 0
for _ in range(m):
    a = input()
    if a in s:
        total += 1
print(total)