abc = [0]*26
s = input().upper()
for c in s:
    abc[ord(c)-ord('A')] += 1

s_abc = sorted(abc,reverse=True)
if s_abc[0] == s_abc[1]:
    print('?')
else:
    for i in range(len(abc)):
        if abc[i] == s_abc[0]:
            print(chr(ord('A')+i))