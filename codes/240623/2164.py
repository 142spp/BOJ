n = int(input())

cards = [x for x in range(1,n+1)]
cur = 0
while(cur < len(cards)-1):
    cards[cur] = -1
    cur += 1
    cards.append(cards[cur])
    cards[cur] = -1
    cur += 1
print(cards[-1])