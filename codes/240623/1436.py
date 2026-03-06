import math

n = int(input())

index = 0
for s in range(1000000000):
    if '666' in str(s):
        index += 1
        if index == n: 
            print(s)
            break
