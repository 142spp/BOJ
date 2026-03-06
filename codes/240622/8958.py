n = int(input())

for _ in range(n):
    ox = input()
    ts = 0
    cs = 1
    for c in ox:
        if c == 'O':
            ts += cs
            cs += 1
        else :
            cs = 1
    print(ts)