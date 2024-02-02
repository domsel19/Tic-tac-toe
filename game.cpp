#include <iostream>
#include <string>
#include <vector>

enum class Symbol { X, O, Empty };

class Field {
 private:
  std::vector<std::vector<Symbol>> field;

 public:
  Symbol player;
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
};
int main() {
  int a, b;
  Field gamefield;
  while (gamefield.game_over() == false) {
    char gamewinner;
    gamefield.printBoard();
    std::cout << "Enter the row and collum you want to take your turn on: ";
    std::cin >> a >> b;
    gamefield.turn(a, b, gamefield.player);
    if (gamefield.winner(gamefield.player) == true) {
      if (gamefield.player == Symbol::X ? gamewinner = 'X' : gamewinner = 'O')
        std::cout << "The winner is: " << gamewinner << std::endl;
      break;
    }
  }

  return 0;
}