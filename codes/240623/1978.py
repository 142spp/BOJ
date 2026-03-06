import math
n = int(input())
nlist = map(int,input().split())

def is_prime(n):
    if n == 1 : return False
    if n == 2 or n == 3 : return True
    for i in range(n):
        for j in range(i+1):
            if i*j == n:
                return False
    return True

p = 0

for m in nlist:
    if is_prime(m):
        p += 1   

print(p)
