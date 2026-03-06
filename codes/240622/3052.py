remains = [0]*42

for _ in range(10):
    n = int(input())
    if remains[n%42] ==0:
        remains[n%42] += 1

sum = 0
for r in remains:
    sum += r
print(sum)
