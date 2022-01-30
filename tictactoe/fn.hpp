using namespace std;

void displayBoard(vector<string> board);
void instructions();
void p1Turn(vector<string> &board, int turn);
void p2Turn(vector<string> &board, int turn);
bool isValid(vector<string> &board, string playerChoice, int turn);
bool play(vector<string> const &board, int turn);