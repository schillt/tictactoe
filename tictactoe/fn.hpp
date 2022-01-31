using namespace std;

/****************************************************************
* I realized vectors are not like arrays and when passed to 
* a function only a copy of the vector is passed, whereas an
* array would be passed with all of its data (I think). As such,
* the board vector needs to be passed by reference so changes
* made by players on the turn are reflected. I am not sure if
* the two bools require it, but I think so, though I think they
* could both be const if needed. I made them references anyway
****************************************************************/

void displayBoard(vector<string> board);
void instructions();
void p1Turn(vector<string> &board, int turn);
void p2Turn(vector<string> &board, int turn);
bool isValid(vector<string> &board, string playerChoice, int turn);
bool play(vector<string> const &board, int turn);
