import sys

class Stack:
    def __init__(self):
        self.slist = [-1]*10000
        self.last_index = -1
        self.s_size = 0
    def push(self, n):
        self.last_index += 1
        self.slist[self.last_index] = n
        self.s_size += 1
    def pop(self):
        if self.s_size == 0:
            return -1
        n = self.slist[self.last_index]
        self.last_index -= 1
        self.s_size -= 1
        return n
    def size(self):
        return self.s_size
    def empty(self):
        if self.s_size == 0:
            return 1
        else: return 0
    def top(self):
        if self.s_size == 0:
            return -1
        return self.slist[self.last_index]
    
n = int(sys.stdin.readline())
stack = Stack()
for _ in range(n):
    args = sys.stdin.readline().split()
    op = args[0]
    arg = 0
    if len(args)>1: 
        arg = int(args[1])
    if op == 'push':
        stack.push(arg)
    elif op == 'pop':
        print(stack.pop())
    elif op == 'size':
        print(stack.size())
    elif op == 'empty':
        print(stack.empty())
    elif op == 'top':
        print(stack.top())