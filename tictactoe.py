main_board = {}
win_check = [[1,2,3],[4,5,6],[7,8,9],[1,4,7],[2,5,8],[3,6,9],[1,5,9],[3,5,7]]

def print_board():
  for i in range(1,len(main_board),3):
    print("_"+main_board[i]+"_|_"+main_board[i+1]+"_|_"+main_board[i+2]+"_")

def check_win(player):
  if player == "X":
    opponent = "O" 
  else: 
    opponent = "X" 
    
  for x in range(0,len(win_check)):
    subarr = win_check[x]
    if main_board[subarr[0]] == main_board[subarr[1]] == main_board[subarr[2]] == player:
      print("Player "+player+" has won and "+opponent+" has lost")
      return True
  return False

def game():
    for i in range(0,9):
      main_board[i+1] = str(i+1)
    print_board()

    turn = "X"
    rounds = 0

    while True:
      move = input("Player "+turn+", its your turn: ")

      if move.isdigit() and int(move) > 0 and int(move) < 10:
        if main_board[int(move)].isdigit():
          main_board[int(move)] = turn
          print_board()
        else:
          print("That position is already filled. TRY AGAIN...")
          print_board()
          continue
      else:
        print("Enter a digit from 1 to 9")
        print_board()
        continue

      if turn == "X":
        turn = "O"
      else:
        turn = "X"
      rounds += 1

      if check_win("X") == True or check_win("O") == True:
        break

      if rounds == 9:
        print("::Its a tie::")
        break
      
    restart = input("Play Again -> Yes(y) or No(n)? ") 
    if  restart == "y" or restart == "Y":   
      game()
    else:
        exit()

game()
