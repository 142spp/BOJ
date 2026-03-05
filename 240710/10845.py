import sys
class Node:
    def __init__(self, data):
        self.data = data
        self.next : Node = None

class Queue:
    def __init__(self):
        self.Qsize = 0
        self.Qfront : Node = None
        self.Qrear : Node = None

    def push(self, data):
        new_node = Node(data)
        if self.Qrear != None:
            self.Qrear.next = new_node
        else :
            self.Qfront = new_node
        self.Qrear = new_node
        self.Qsize += 1
        
    def pop(self):
        if self.Qfront == None:
            return -1
        temp_data = self.Qfront.data
        self.Qfront = self.Qfront.next        
        self.Qsize -= 1
        if self.Qsize == 0:
            self.Qrear = None
        return temp_data
    
    def size(self):
        return self.Qsize
        
    def empty(self):
        if self.Qsize == 0 :
            return 1
        else : return 0
    
    def front(self):
        if self.Qfront == None:
            return -1
        return self.Qfront.data
    
    def back(self):
        if self.Qrear == None:
            return -1
        return self.Qrear.data
    
n = int(input())
q = Queue()

for _ in range(n):
    oper = input().split()
    if oper[0] == 'push':
        q.push(int(oper[1]))
    elif oper[0] == 'pop':
        print(q.pop())
    elif oper[0] == 'size':
        print(q.size())
    elif oper[0] == 'empty':
        print(q.empty())
    elif oper[0] == 'front':
        print(q.front())
    elif oper[0] == 'back':
        print(q.back())
        
from collections import deque

deque1 = deque()
