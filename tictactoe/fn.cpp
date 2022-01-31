#include <iostream>
#include <vector>
#include <string>
#include "fn.hpp"

using namespace std; //no std

/*********************************************************
 * displayBoard performs the formatting and output of the
 * board and is called throughout program as board updates
 * *******************************************************/
void displayBoard(vector<string> board)
{
  cout << "    A   B   C\n"; //horizontal grid coordinates for user
  int row = 0; //vertical grid coordinates for user (end result example: A1)
  for (int i = 0; i < board.size(); i++)
      {
        if (i == 6 || i == 12 || i == 18)
        {
          cout <<  "   ---+---+---\n";
        }
        if (i == 0 || i == 6 || i == 12)
        {
          row++;
          cout << row << "  ";   
        }
        if (board[i] == "0")
        {
          cout << " ";
        }
        else if (board[i] == "0\n")
        {
          cout << " \n";
        }
        else
        {
        cout << board[i];
        }
      }
    cout << endl;
};

/*********************************************************
 * instructions provides brief instructions about how to 
 * play and informs players of roles.
 * *******************************************************/
void instructions()
{
  cout << "======================================================\n"
            << "Player 1 begins. Player 2 follows and turns are taken.\n"
            << "Select a quadrant (example: A2) to fill.\n"
            << "Player 1 is 'X'.\n" << "Player 2 is 'O'.\n";
};

/*********************************************************
 * p1turn gives instructions and indications to the
 * player whose turn it is. Loops until valid inputs and
 * displays the board after each player's turn.
 * *******************************************************/
void p1Turn(vector<string> &board, int turn)
{
  string p1Choice; 

  do
  {
    cout << "\nPlayer " << turn << "\n"
              << "Choose a quadrant to place an \'X\': ";
    cin  >> p1Choice;
    cout << endl;
  } 
  while (!isValid(board, p1Choice, turn));

  return;
};

/*********************************************************
 * p1turn gives instructions and indications to the
 * player whose turn it is. Loops until valid inputs and
 * displays the board after each player's turn.
 * *******************************************************/
void p2Turn(vector<string> &board, int turn)
{
  string p2Choice; 

  do
  {
    cout << "\nPlayer " << turn << "\n"
              << "Choose a quadrant to place an \'O\': ";
    cin  >> p2Choice;
    cout << endl;
  } 
  while (!isValid(board, p2Choice, turn));
    
  return;
};

/*********************************************************
 * isValid converts user input to board index values and
 * edits the board with an x or o depending on if turn == 1
 * *******************************************************/
bool isValid(vector<string> &board,string playerChoice, int turn)
{
  if (playerChoice == "A1")
  {
    if (board[1] == "0")
    {
      if (turn == 1)
      {
        board[1] = "X";
      }
      else
      {
        board[1] = "O";
      }
      return true;
    }
  }

  if (playerChoice == "B1")
  {
    if (board[3] == "0")
    {
      if (turn == 1)
      {
        board[3] = "X";
      }
      else
      {
        board[3] = "O";
      }
      return true;
    }
  }
  
 if (playerChoice == "C1")
  {
    if (board[5] == "0\n")
    {
      if (turn == 1)
      {
        board[5] = "X\n";
      }
      else
      {
        board[5] = "O\n";
      }
      return true;
    }
  }
  
 if (playerChoice == "A2")
  {
    if (board[7] == "0")
    {
      if (turn == 1)
      {
        board[7] = "X";
      }
      else
      {
        board[7] = "O";
      }
      return true;
    }
  }
 if (playerChoice == "B2")
  {
    if (board[9] == "0")
    {
      if (turn == 1)
      {
        board[9] = "X";
      }
      else
      {
        board[9] = "O";
      }
      return true;
    }
  }
  if (playerChoice == "C2")
  {
    if (board[11] == "0\n")
    {
      if (turn == 1)
      {
        board[11] = "X\n";
      }
      else
      {
        board[11] = "O\n";
      }
      return true;
    }
  }
  if (playerChoice == "A3")
  {
    if (board[13] == "0")
    {
      if (turn == 1)
      {
        board[13] = "X";
      }
      else
      {
        board[13] = "O";
      }
      return true;
    }
  }
  if (playerChoice == "B3")
  {
    if (board[15] == "0")
    {
      if (turn == 1)
      {
        board[15] = "X";
      }
      else
      {
        board[15] = "O";
      }
      return true;
    }
  }
  if (playerChoice == "C3")
  {
    if (board[17] == "0\n")
    {
      if (turn == 1)
      {
        board[17] = "X\n";
      }
      else
      {
        board[17] = "O\n";
      }
      return true;
    }
  }
  
  cout << "Invalid Input. Try a new selection\n" << endl;
  
  return false;

};

/*********************************************************
 * play determines if the game has finished and who
 * won. Sends false value back to main to end game loop.
 * *******************************************************/
bool play(vector<string> const &board, int turn)
{
  /******************************************
  * Possible combos:
  * A123* B123* C123*
  * A1B1C1* A2B2C2* A3B3C3*
  * A1B2C3* A3B2C1*
  * Indexes are odd numbers on cross
  *******************************************/

  if ((board[1] == "X" && board[3] == "X" && board[5] == "X\n")  || (board[1] == "X" && board[7] == "X" && board[13] == "X")
   || (board[1] == "X" && board[9] == "X" && board[17] == "X\n") || (board[3] == "X" && board[9] == "X" && board[15] == "X")
   || (board[7] == "X" && board[9] == "X" && board[11] == "X\n") || (board[13] == "X" && board[15] == "X" && board[17] == "X\n")
   || (board[13] == "X" && board[9] == "X" && board[5] == "X\n") || (board[5] == "X\n" && board[11] == "X\n" && board[17] == "X\n"))
  {
    cout << "\nPlayer 1 is the Winner!\n"
              << "Game Over!\n";
    return false;
  }
  else if ((board[1] == "O" && board[3] == "O" && board[5] == "O\n")  || (board[1] == "O" && board[7] == "O" && board[13] == "O")
   || (board[1] == "O" && board[9] == "O" && board[17] == "O\n") || (board[3] == "O" && board[9] == "O" && board[15] == "O")
   || (board[7] == "O" && board[9] == "O" && board[11] == "O\n") || (board[13] == "O" && board[15] == "O" && board[17] == "O\n")
   || (board[13] == "O" && board[9] == "O" && board[5] == "O\n") || (board[5] == "O\n" && board[11] == "O\n" && board[17] == "O\n"))
  {
    cout << "\nPlayer 2 is the Winner!\n"
              << "Game Over!\n";
    return false;
  }
  return true;
};
