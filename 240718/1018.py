n, m = map(int,input().split())

chess_board = []

for _ in range(n):
    chess_board.append(input())

min_count = 8*8
w_board = ['WBWBWBWB','BWBWBWBW']*4
b_board = ['BWBWBWBW','WBWBWBWB']*4

for i in range(n):
    for j in range(m):
        try:
            w_count = 0
            for x in range(i,i+8):
                for y in range(j,j+8):
                    if chess_board[x][y] != w_board[x-i][y-j] :
                        w_count += 1
            b_count = 0
            for x in range(i,i+8):
                for y in range(j,j+8):
                    if chess_board[x][y] != b_board[x-i][y-j] :
                        b_count += 1
            min_count = min([min_count,w_count,b_count])
        except:
            pass

print(min_count)