n = int(input())

for i in range(0,n-1):
    print(f'{"*"*(1+2*i):>{n+i}}')
for i in range(n-1,-1,-1):
    print(f'{"*"*(1+2*i):>{n+i}}')