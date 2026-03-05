n = int(input())

stack = [0]
num = [x for x in range(n,0,-1)]
ans = []
for _ in range(n):
    k = int(input())
    if k == stack[-1]:
        stack.pop()
        ans.append('-')
    elif k < stack[-1]:
        ans = []
        break
    elif k > stack[-1]:
        while k != stack[-1] :
            stack.append(num.pop())
            ans.append('+')
        stack.pop()
        ans.append('-')

if len(ans) == 0 :
    print('NO')
else :
    for a in ans:
        print(a)