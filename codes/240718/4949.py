sl_b = [('(',')'),('[',']')]

while True:
    blanks = []
    s = input()
    ans = 'yes'
    if s == '.': break
    for c in s:
        if c == '(':
            blanks.append(1)
        elif c == ')':
            if len(blanks) > 0 and blanks[-1] == 1:
                blanks.pop()
            else :
                ans = 'no'
                break
        elif c == '[':
            blanks.append(2)
        elif c == ']':
            if len(blanks) > 0 and blanks[-1] == 2:
                blanks.pop()
            else:
                ans = 'no'
                break
            
    if len(blanks) != 0:
        ans = 'no'
    print(ans)