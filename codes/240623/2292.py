n = int(input())

c = 1
m = 1
s = 0
while(True):
    s += m
    if n <= s:
        break
    m = c*6
    c += 1
print(c)