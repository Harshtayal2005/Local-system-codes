import random

board = ["-", "-", "-",
        "-", "-", "-",
        "-", "-", "-"]

possibleWins = [[0,1,2],[3,4,5],
                [6,7,8],[0,3,6],
                [1,4,7],[2,5,8],
                [0,4,8],[2,4,6]]

def getRandomMove(board, player):
    l = [i for i in range(9) if board[i]=='-']
    return random.choice(l)

def getMove(board, player):
    for i in possibleWins:
        if ((board[i[0]] == board[i[1]] == player and board[i[2]]=='-') 
        or (board[i[0]] == board[i[2]] == player and board[i[1]] == '-') 
        or (board[i[1]] == board[i[2]] == player and board[i[0]] == '-')):
            for j in i:
                if (board[j]=='-'):
                    # board[j] = 'X'
                    return j
    
    oppo = 'O' if player=='X' else 'X'
    # check for defending condition
    for i in possibleWins:
        if ((board[i[0]] == board[i[1]] == oppo and board[i[2]]=='-') 
        or (board[i[0]] == board[i[2]] == oppo and board[i[1]] == '-') 
        or (board[i[1]] == board[i[2]] == oppo and board[i[0]] == '-')):
            for j in i:
                if (board[j]=='-'):
                    # board[j] = 'X'
                    return j
    l = [j for j in range(9) if board[j]=='-' ]
    return random.choice(l)
    
def getBestMove(board, player):
    # check for winning condition
    for i in possibleWins:
        if ((board[i[0]] == board[i[1]] == player and board[i[2]]=='-') 
        or (board[i[0]] == board[i[2]] == player and board[i[1]] == '-') 
        or (board[i[1]] == board[i[2]] == player and board[i[0]] == '-')):
            for j in i:
                if (board[j]=='-'):
                    # board[j] = player
                    return j

    oppo = 'O' if player=='X' else 'X'
    # check for defending condition
    for i in possibleWins:
        if ((board[i[0]] == board[i[1]] == oppo and board[i[2]]=='-') 
        or (board[i[0]] == board[i[2]] == oppo and board[i[1]] == '-') 
        or (board[i[1]] == board[i[2]] == oppo and board[i[0]] == '-')):
            for j in i:
                if (board[j]=='-'):
                    # board[j] = 'X'
                    return j

    if board[4] == '-':
        return 4
    # try corner cases 
    for i in [0,2,6,8]:
        if (board[i] == '-'):
            # board[i] = 'X'
            return i
    else:
        l = [j for j in range(9) if board[j]=='-' ]
        # board[random.choice(l)] = 'X'
        return random.choice(l)
        

                 
        

def print_board(board):
    print(board[0] + " | " + board[1] + " | " + board[2])
    print(board[3] + " | " + board[4] + " | " + board[5])
    print(board[6] + " | " + board[7] + " | " + board[8])

def take_turn(player,board):
    # print(player + "'s turn.")
    print("-----------")
    if player == "X":
        # move = getBestMove(board, player)
        # move = getRandomMove(board, player)
        move = getMove(board,player)
        # print(f"Random Move: {randomMove}")
        # print(f"Avg Move: {avgMove}")
        # print(f"Suggestion: {bestMove}")
        position = move
        # position = int(input("Choose a position from 1-9: "))
        # while position not in ["1", "2", "3", "4", "5", "6", "7", "8", "9"]:
        #     position = input("Invalid input. Choose a position from 1-9: ")
        board[position] = player
    else:
        # Computer player makes a random move
        board[getMove(board,'O')] = player
        # board[getBestMove(board,'O')] = player
        print_board(board)
    
    # while board[position] != "-":
    #     if player == "X":
    #         position = int(input("Position already taken. Choose a different position: "))
    #     else:
    #         position = random.choice(empty_positions)
    

def check_game_over(board):
    if (board[0] == board[1] == board[2] != "-") or \
       (board[3] == board[4] == board[5] != "-") or \
       (board[6] == board[7] == board[8] != "-") or \
       (board[0] == board[3] == board[6] != "-") or \
       (board[1] == board[4] == board[7] != "-") or \
       (board[2] == board[5] == board[8] != "-") or \
       (board[0] == board[4] == board[8] != "-") or \
       (board[2] == board[4] == board[6] != "-"):
        return "win"
    elif "-" not in board:
        return "tie"
    else:
        return "play"

def play_game():
    board = ["-", "-", "-",
        "-", "-", "-",
        "-", "-", "-"]
    print_board(board)
    current_player = "X"
    game_over = False
    while not game_over:
        take_turn(current_player, board)
        game_result = check_game_over(board)
        if game_result == "win":
            print(current_player + " wins!")
            game_over = True
            return 1 if current_player=='X' else -1
        elif game_result == "tie":
            print("It's a tie!")
            game_over = True
            return 0
        else:
            current_player = "O" if current_player == "X" else "X"
Win=0
Lose=0
for i in range(1000):
    # bestMoveWin+=play_game()
    temp = play_game()

    if (temp==1):
        Win+=1
    elif temp==-1:
        Lose+=1
    print("--------------------------")
print(f"Win:  {Win}")
print(f"Lose:  {Lose}")