#include <iostream>
#include <string>
#include <vector>

enum class Symbol { X, O, Empty };

class Field {
 private:
  std::vector<std::vector<Symbol>> field;

 public:
  Symbol player = Symbol::X;
  Field() : field(3, std::vector<Symbol>(3, Symbol::Empty)) {}

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
  void turn(int row, int col, Symbol player) {
    if (row < 3 && row >= 0 && col >= 0 && col < 3 &&
        field[row][col] == Symbol::Empty) {
      field[row][col] = player;
    }
  }
  bool check_field(int a, int b) { return field[a][b] == Symbol::Empty; }
};
int main() {
  int a, b;
  Field gamefield;
  while (!gamefield.game_over()) {
    char gamewinner;
    gamefield.printBoard();
    std::cout << "Enter the row and column you want to take your turn on: ";
    std::cin >> a >> b;
    if (std::cin.fail() || a < 0 || a >= 3 || b < 0 || b >= 3 ||
        gamefield.check_field(a, b) != true) {
      std::cout
          << "Your input was invalid. Please enter the row and column again."
          << std::endl;
      std::cin.clear();
      std::cin >> a >> b;
      continue;
    }

    gamefield.turn(a, b, gamefield.player);
    if (gamefield.winner(gamefield.player) == true) {
      gamewinner = (gamefield.player == Symbol::X) ? 'X' : 'O';
      gamefield.printBoard();
      std::cout << "The winner is: " << gamewinner << std::endl;
      break;
    }
    if (gamefield.player == Symbol::X) {
      gamefield.player = Symbol::O;
    } else {
      gamefield.player = Symbol::X;
    }
  }

  return 0;
}