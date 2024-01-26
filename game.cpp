#include <iostream>
#include <string>
#include <vector>

class Field {
 private:
  std::vector<std::vector<std::string>> field;

 public:
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
    }
  }
  void setcirc(int r, int c) {
    if (r % 2 == 0 && c % 2 == 0) {
      field[r][c] = "O";
    }
  }
  void reset() {
    for (int i = 0; i < 5; i += 2) {
      for (int j = 0; j < 5; j += 2) {
        field[i][j] = "";
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
};
int main() {
  Field gamefield;
  gamefield.print();
  gamefield.setcross(0, 0);
  gamefield.print();
  gamefield.reset();
  gamefield.print();
  return 0;
}