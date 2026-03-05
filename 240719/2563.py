arr = [[0 for x in range(100)] for y in range(100)]
n = int(input())

for _ in range(n):
    l, d = map(int,input().split())
    for i in range(l,l+10):
        for j in range(d,d+10):
            try:
                arr[i][j] = 1
            except:
                pass

area = 0
for i in range(len(arr)):
    for j in range(len(arr)):
        if arr[i][j] == 1:
            area += 1

print(area)