#include <iostream>
#include <vector>

enum class Symbol { X, O, Empty };

class TicTacToe {
 private:
  std::vector<std::vector<Symbol>> board;

 public:
  TicTacToe() : board(3, std::vector<Symbol>(3, Symbol::Empty)) {}

  void printBoard() {
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        char symbolChar = (board[i][j] == Symbol::X)
                              ? 'X'
                              : ((board[i][j] == Symbol::O) ? 'O' : ' ');
        std::cout << symbolChar << "\t";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }

  bool isWinner(Symbol player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
      if (board[i][0] == player && board[i][1] == player &&
          board[i][2] == player) {
        return true;  // Horizontal
      }
      if (board[0][i] == player && board[1][i] == player &&
          board[2][i] == player) {
        return true;  // Vertical
      }
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player &&
        board[2][2] == player) {
      return true;  // Diagonal
    }
    if (board[0][2] == player && board[1][1] == player &&
        board[2][0] == player) {
      return true;  // Diagonal /
    }

    return false;  // No winner
  }

  void makeMove(int row, int col, Symbol player) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 &&
        board[row][col] == Symbol::Empty) {
      board[row][col] = player;
    }
  }
};

int main() {
  TicTacToe game;
  Symbol currentPlayer = Symbol::X;

  while (true) {
    game.printBoard();

    int row, col;
    std::cout << "Enter your move (row and column): ";
    std::cin >> row >> col;

    game.makeMove(row, col, currentPlayer);

    if (game.isWinner(currentPlayer)) {
      game.printBoard();
      std::cout << "Player " << ((currentPlayer == Symbol::X) ? 'X' : 'O')
                << " wins!" << std::endl;
      break;
    }

    // Switch player for the next turn
    currentPlayer = (currentPlayer == Symbol::X) ? Symbol::O : Symbol::X;
  }

  return 0;
}