n = input()
s = input()

h = 0
r = 1
m = 1234567891

for c in s:
    h += (ord(c)-ord('a')+1)*r%m
    r *= 31
    if r > m : r = r%m

print(h%m)