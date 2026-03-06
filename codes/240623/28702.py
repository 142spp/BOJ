ans_num = 0
for i in range(3):
    inp_num = input()
    if inp_num == 'Fizz':
        continue
    if inp_num == 'Buzz':
        continue
    if inp_num == 'FizzBuzz':
        continue
    ans_num = int(inp_num) + (3-i)

answer = ""
if ans_num%3==0 and ans_num%5==0: answer = "FizzBuzz"
elif ans_num%3==0 : answer = "Fizz"
elif ans_num%5==0 : answer = "Buzz"
else : answer = str(ans_num) 
print(answer)