import sys

S = [0]*21

n = int(sys.stdin.readline().rstrip())

for _ in range(n):
    oper = list(map(str,sys.stdin.readline().split()))
    if oper[0] == 'add':
        S[int(oper[1])] = 1
        continue
    elif oper[0] == 'remove':
        S[int(oper[1])] = 0
        continue
    elif oper[0] == 'check':
        print(S[int(oper[1])])
        continue
    elif oper[0] == 'toggle':
        S[int(oper[1])] = 1 - S[int(oper[1])]
        continue
    elif oper[0] == 'all':
        for i in range(1,len(S)):
            S[i] = 1
        continue
    elif oper[0] == 'empty':
        for i in range(1,len(S)):
            S[i] = 0