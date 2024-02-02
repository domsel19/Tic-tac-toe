#include <iostream>
#include <string>
#include <vector>

// creates a class to work with two different symbols representing the two
// players
enum class Symbol { X, O, Empty };

class Field {
 private:
  // allocates the space for a two-dimensional vector of Symbols
  std::vector<std::vector<Symbol>> field;

 public:
  // sets the current player two Symbol::X, which is the starter
  Symbol player = Symbol::X;
  // constructor of the class Field
  Field() : field(3, std::vector<Symbol>(3, Symbol::Empty)) {}

  // function to print the board in terminal
  void printBoard() {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        char playersymbol = (field[i][j] == Symbol::X)
                                ? 'X'
                                : ((field[i][j] == Symbol::O) ? 'O' : ' ');
        std::cout << playersymbol << "\t";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }
  // function to check if the max. ammount of turns is taken
  bool game_over() {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (field[i][j] == Symbol::Empty) {
          return false;
        }
      }
    }
    return true;
  }
  // function to check if someone won the game
  bool winner(Symbol win_player) {
    for (int i = 0; i < 3; i++) {
      if (field[i][0] == win_player && field[i][1] == win_player &&
          field[i][2] == win_player) {
        return true;
      }
    }
    for (int j = 0; j < 3; j++) {
      if (field[0][j] == win_player && field[1][j] == win_player &&
          field[2][j] == win_player) {
        return true;
      }
    }
    if (field[0][0] == win_player && field[1][1] == win_player &&
        field[2][2] == win_player) {
      return true;
    }
    if (field[0][2] == win_player && field[1][1] == win_player &&
        field[2][0] == win_player) {
      return true;
    }
    return false;
  }
  // function to take the turn of any player
  void turn(int row, int col, Symbol player) {
    if (row < 3 && row >= 0 && col >= 0 && col < 3 &&
        field[row][col] == Symbol::Empty) {
      field[row][col] = player;
    }
  }
  // function to check for wrong input, more precisely if the field was already
  // filled with a symbol
  bool check_field(int a, int b) { return field[a][b] == Symbol::Empty; }
};
int main() {
  // allocates two ints for the input of the users
  int a, b;
  // constructs the class Field with the name gamefield
  Field gamefield;
  // checks if all possible spots on the field are already in use
  while (!gamefield.game_over()) {
    // allocates a char named gamewinner
    char gamewinner;
    // prints the board
    gamefield.printBoard();
    // prints the prompt to enter row and column
    std::cout << "Enter the row and column you want to take your turn on: ";
    // takes the input of row and column
    std::cin >> a >> b;
    // checks for correct input
    if (std::cin.fail() || a < 0 || a >= 3 || b < 0 || b >= 3 ||
        gamefield.check_field(a, b) != true) {
      // prints an error message in case the input was invalid
      std::cout
          << "Your input was invalid. Please enter the row and column again."
          << std::endl;
      // deletes the invalid input
      std::cin.clear();
      // takes the new, correct input
      std::cin >> a >> b;
      continue;
    }
    // calls the function turn to take a turn for the player
    gamefield.turn(a, b, gamefield.player);
    // sets the gamewinner if someone won the game
    if (gamefield.winner(gamefield.player) == true) {
      gamewinner = (gamefield.player == Symbol::X) ? 'X' : 'O';
      // prints the board if someone won
      gamefield.printBoard();
      // prints the symbol of the winner
      std::cout << "The winner is: " << gamewinner << std::endl;
      break;
    }
    // changes the turn of the player (X -> O or O -> X)
    if (gamefield.player == Symbol::X) {
      gamefield.player = Symbol::O;
    } else {
      gamefield.player = Symbol::X;
    }
  }
  return 0;
}