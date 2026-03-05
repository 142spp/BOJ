from math import sqrt,ceil

def is_prime(n):
    if n == 1: return False
    if n == 2 or n == 3 : return True
    for i in range(2, ceil(sqrt(n))+1):
        if n%i == 0:
            return False
    return True

m,n = map(int,input().split())

for i in range(m,n+1):
    if is_prime(i):
        print(i)
