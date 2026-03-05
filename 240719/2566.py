maximum = 0
maxindex = 0,0
for i in range(9):
    arr = list(map(int,input().split()))
    for j in range(9):
        maximum = max(maximum,arr[j])
        if maximum == arr[j]:
            maxindex = i+1,j+1
print(f'{maximum}\n{maxindex[0]} {maxindex[1]}')