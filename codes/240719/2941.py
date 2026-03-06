c_alpha = ['c=','c-','dz=','d-','lj','nj','s=','z=']

s = input()

for c in c_alpha:
    s = s.replace(c,'a')

print(len(s))