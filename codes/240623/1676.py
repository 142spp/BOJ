n = int(input())

t = 0
f = 0
for i in range(1,n+1):
    tj = 0
    for j in range(1,10):
        if i%(2**j) != 0:
            break
        tj += 1
    fj = 0
    for j in range(1,10):
        if i%(5**j) != 0:
            break
        fj += 1
    t += tj
    f += fj


print(min(t,f))