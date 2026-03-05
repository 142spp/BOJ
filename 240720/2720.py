n = int(input())
table = [25,10,5,1]
for _ in range(n):
    ans = [0,0,0,0]
    money = int(input())
    for i in range(len(table)):
        ans[i] = money // table[i]
        money %= table[i]
    for a in ans:
        print(a, end=" ")
    print("")