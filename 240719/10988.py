s = input()
r_s = s[::-1]
ans = 1
for i in range(len(s)):
    if s[i] != r_s[i]:
        ans = 0
print(ans)