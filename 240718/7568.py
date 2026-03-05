n = int(input())
mans = []
for _ in range(n):
    weight, height = map(int,input().split())
    mans.append((weight,height))

loses = [0]*n
for i in range(n):
    lose_count = 0
    for j in range(n):
        if i == j : continue
        if mans[i][0] < mans[j][0] and mans[i][1] < mans[j][1] :
            lose_count += 1
    loses[i] = lose_count

for w in loses:
    print(w+1)