from collections import deque

n, k = map(int,input().split())

jq = deque([x for x in range(1,n+1)])
print("<",end="")
while len(jq) > 0:
    jq.rotate(-k)
    print(jq.pop(), end="")
    if len(jq) > 0:
        print(", ",end="")
print(">",end="")