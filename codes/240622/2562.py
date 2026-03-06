max_val = 0
max_index = 0
for i in range(9):
    n = int(input())
    if n > max_val:
        max_val = n
        max_index = i
print(f"{max_val}\n{max_index+1}")