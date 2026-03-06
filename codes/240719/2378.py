n,m = map(int,input().split())
a_arr = []
b_arr = []

for _ in range(n):
    a_arr.append(list(map(int,input().split())))
for _ in range(n):
    b_arr.append(list(map(int,input().split())))

for i in range(n):
    for j in range(m):
        print(a_arr[i][j]+b_arr[i][j], end=" ")
    print("")