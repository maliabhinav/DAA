# Function to print board
def print_board(board, N):
    for row in range(N):
        for col in range(N):
            if board[row][col] == 1:
                print("Q", end=" ")
            else:
                print(".", end=" ")
        print("")
    print("")

# Function to check queen is safe at particular position or not
def is_safe(board, row, col, N):
    for i in range(col):
        if board[row][i] == 1:
            return False
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    for i, j in zip(range(row, N), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    return True

    # Below code uses simple while and perform similar function like above code
    # i = col - 1
    # while i >= 0:
    #     if board[row][i] == 1:
    #         return False
    #     i -= 1
    # i, j = row - 1, col - 1
    # while i >= 0 and j >= 0:
    #     if board[i][j] == 1:
    #         return False
    #     i -= 1
    #     j -= 1
    # i, j = row + 1, col - 1
    # while i < N and j >= 0:
    #     if board[i][j] == 1:
    #         return False
    #     i += 1
    #     j -= 1
    # return True


def solve_n_queen(board, col, N):
    if col >= N:
        print_board(board, N)
        return True
    
    # This code for printing all possible solution
    res = False
    for i in range(N):
        if is_safe(board, i, col, N):
            board[i][col] = 1
            res = solve_n_queen(board, col + 1, N) or res
            board[i][col] = 0 
    return res
    # This code for printing single solution
    # for i in range(N):
    #     if is_safe(board, i, col, N):
    #         board[i][col] = 1
    #         if solve_n_queen(board, col + 1, N):
    #             return True
    #         board[i][col] = 0
    # return False

# Simple function for creating board and printing board and handle base case like 2 and 3 queen problems
def n_queen(N):
    board = [[0 for _ in range(N)] for _ in range(N)]
    if not solve_n_queen(board, 0, N):
        print(f"No solution exists for {N} queens.")

n = int(input("Enter size of board : "))
n_queen(n)