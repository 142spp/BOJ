stack = []
n = int(input())
for _ in range(n):
    o = input().split()
    if o[0] == '1':
        stack.append(int(o[1]))
    elif o[0] == '2':
        if len(stack) > 0:
            print(stack.pop())
        else:
            print(-1)
    elif o[0] == '3':
        print(len(stack))
    elif o[0] == '4':
        if len(stack) > 0:
            print(0)
        else:
            print(1)
    elif o[0] == '5':
        if len(stack) > 0:
            print(stack[-1])
        else:
            print(-1)