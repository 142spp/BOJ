bell = ['ABC','DEF','GHI','JKL','MNO','PQRS','TUV','WXYZ']

s = input()
time = 0
for c in s:
    for i in range(len(bell)):
        if c in bell[i]:
            time += i+3
print(time)