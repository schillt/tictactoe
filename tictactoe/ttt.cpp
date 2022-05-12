#include <iostream>
#include <string>
#include <vector>
#include "fn.hpp"

using namespace std; //don't like std:: too much typing

/*********************************************************
 * main provides the board setup in vector for use
 * throughout program and calls game functions in loop as
 * needed until game is over.
 * *******************************************************/
int main()
{

  vector<string> board = {
    //    A           B           C
    " ", "0", " | ", "0", " | ", "0\n", // 1
    " ", "0", " | ", "0", " | ", "0\n", // 2
    " ", "0", " | ", "0", " | ", "0\n"  // 3
                                    };

  displayBoard(board);
  instructions();
  int turn = 1;
  int rounds = 0;

  while (play(board, turn))
  {
    if (rounds == 9)
    {
      cout << "Tie!\n";
      break;
    }
    if (turn == 1)
    {
      p1Turn(board, turn);
      displayBoard(board);
      turn = 2;
    }
    else if (play(board, turn) && turn == 2)
    {
      p2Turn(board, turn);
      displayBoard(board);
      turn = 1;
    }
    rounds++;
  }
  return 0;
}
