chess = [1,1,2,2,2,8]
inputs = list(map(int,input().split()))
ans = [0]*len(chess)
for i in range(len(chess)):
    ans[i] = chess[i] - inputs[i]

for a in ans:
    print(a,end=" ")