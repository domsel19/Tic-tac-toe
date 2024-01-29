#include <iostream>
#include <string>
#include <vector>

class Field {
 private:
  std::vector<std::vector<std::string>> field;
  int player = 0;

 public:
  int winner = -1;
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
    if (r % 2 == 0 && c % 2 == 0 && field[r][c] == " ") {
      field[r][c] = "X";
      player++;
      wino();
    }
  }
  void setcirc(int r, int c) {
    if (r % 2 == 0 && c % 2 == 0 && field[r][c] == " ") {
      field[r][c] = "O";
      player++;
      winx();
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
  void winx() {
    if (field[0][0] == "X" && field[0][2] == "X" && field[0][4] == "X") {
      winner = 1;
    } else if (field[0][0] == "X" && field[2][2] == "X" && field[4][4] == "X") {
      winner = 1;
    } else if (field[2][0] == "X" && field[2][2] == "X" && field[2][4] == "X") {
      winner = 1;
    } else if (field[4][0] == "X" && field[4][2] == "X" && field[4][4] == "X") {
      winner = 1;
    } else if (field[2][0] == "X" && field[2][2] == "X" && field[2][4] == "X") {
      winner = 1;
    } else if (field[0][0] == "X" && field[2][0] == "X" && field[4][0] == "X") {
      winner = 1;
    }
  }
  void wino() {
    if (field[0][0] == "O" && field[0][2] == "O" && field[0][4] == "O") {
      winner = 2;
    } else if (field[0][0] == "O" && field[2][2] == "O" && field[4][4] == "O") {
      winner = 2;
    } else if (field[2][0] == "O" && field[2][2] == "O" && field[2][4] == "O") {
      winner = 2;
    } else if (field[4][0] == "O" && field[4][2] == "O" && field[4][4] == "O") {
      winner = 2;
    } else if (field[2][0] == "O" && field[2][2] == "O" && field[2][4] == "O") {
      winner = 2;
    } else if (field[0][0] == "O" && field[2][0] == "O" && field[4][0] == "O") {
      winner = 2;
    }
  }
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
  while (gamefield.winner == -1) {
    gamefield.print();
    std::cout << "Enter the values of your next choice of field with coma "
                 "seperation: ";
    std::cin >> a >> b;
    gamefield.turn(a, b);
  }
  printf("The winner is Player: %i \n", gamefield.winner);
  return 0;
}