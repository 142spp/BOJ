n = int(input())

five = n // 5
remain = n % 5

while(True):
    if five < 0 :
        print(-1)
        break
    if (n - five*5 ) % 3 == 0:
        print(five + (n-five*5)//3)
        break
    else:
        five -= 1