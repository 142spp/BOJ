import sys

def round2(num:float) -> int:
    if num - int(num) >= 0.5:
        return int(num) + 1
    else:
        return int(num)

# 파이썬의 round 함수는 0.5 로 끝나는 수가 있을 시 가까운 짝수로 반올림 시킨다.
# 따라서 직관적인 반올림과는 차이가 있음.

n = int(input())
i_list = []
for _ in range(n):
    i_list.append(int(sys.stdin.readline().rstrip()))

s_list = sorted(i_list)

cut = int(round2(n*0.15))
try:
    if cut > 0 :
        print(round2(sum(s_list[cut:-cut])/(n-2*cut)))
    else :
        print(round2(sum(s_list)/n))
except:
    print(0)