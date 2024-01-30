#include <iostream>
#include <string>
#include <vector>

enum class Symbol { X, O, Empty };

class Field {
 private:
  std::vector<std::vector<std::string>> field;

 public:
  int player = 0;
  bool win_ = false;
  Field() : field(5, std::vector<std::string>(5, " ")) {
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        if (j % 2 == 1 && i % 2 == 1) {
          field[i][j] = "|------";
        } else if (j % 2 == 1 && i % 2 == 0) {
          field[i][j] = "|";
        }
        if (i % 2 == 1 && j % 2 == 0) {
          field[i][j] = "-------";
        }
      }
    }
  }
  void setcross(int r, int c) {
    if (r % 2 == 0 && c % 2 == 0) {
      field[r][c] = "X";
      player++;
      win();
    }
  }
  void setcirc(int r, int c) {
    if (r % 2 == 0 && c % 2 == 0) {
      field[r][c] = "O";
      player++;
      win();
    }
  }
  void reset() {
    for (int i = 0; i < 5; i += 2) {
      for (int j = 0; j < 5; j += 2) {
        field[i][j] = " ";
      }
    }
  }
  void print() {
    for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < 5; ++j) {
        std::cout << field[i][j] << "\t";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }
  /*void win() {
    if (counter > 3) {
      if (field[0][0] == field[0][2] && field[0][0] == field[0][4]) {
        win_ = true;
      } else if (field[0][0] == field[2][2] && field[0][0] == field[4][4]) {
        win_ = true;
      } else if (field[2][0] == field[2][2] && field[2][0] == field[2][4]) {
        win_ = true;
      } else if (field[4][0] == field[4][2] && field[4][0] == field[4][4]) {
        win_ = true;
      } else if (field[0][0] == field[2][0] && field[0][0] == field[4][0]) {
        win_ = true;
      } else if (field[0][0] == field[0][2] && field[0][0] == field[0][4]) {
        win_ = true;
      } else if (field[0][2] == field[2][2] && field[0][2] == field[4][2]) {
        win_ = true;
      } else if (field[0][4] == field[2][4] && field[0][4] == field[4][4]) {
        win_ = true;
      } else if (field[4][0] == field[2][2] && field[4][0] == field[0][4]) {
        win_ = true;
      } else {
        win_ = false;
      }
    }
  }*/
  bool isWinner() {}
  void turn(int a, int b) {
    if (player % 2 == 0) {
      setcross(a, b);
    } else {
      setcirc(a, b);
    }
  }
};
int main() {
  Field gamefield;
  int a, b;
  while (gamefield.win_ == false) {
    gamefield.print();
    std::cout << "Enter the values of your next choice of field with space "
                 "seperation: ";
    std::cin >> a >> b;
    gamefield.turn(a, b);
  }
  std::cout << "The winner is Player" << (gamefield.player % 2) + 1 << "!";
  return 0;
}