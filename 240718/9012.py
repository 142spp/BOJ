n = int(input())

for _ in range(n):
    x = 0
    ans = 'YES'
    blanks = input()
    for b in blanks:
        if b == '(' : x += 1
        if b == ')' : x -= 1
        if x < 0 : 
            ans = 'NO'
            break
    if x != 0 : ans = 'NO'
    print(ans)
    
    