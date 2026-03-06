n,k = map(int,input().split())

ans = 1

for i in range(k):
    ans *= n
    n -= 1
for i in range(k):
    ans /= i+1
    
print(int(ans))