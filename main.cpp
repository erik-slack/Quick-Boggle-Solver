#include <iostream>
#include <iomanip>
#include "Dictionary.h"
#include "Board.h"
using namespace std;


int main(int argc, char* argv[])
{
	string dictionary_choice = argv[1];
	string board_choice = argv[2];
	string save_choice = argv[3];

	Dictionary dic1;
	Board board1;

	dic1.loadDictionary(dictionary_choice);
	//dic1.printDictionary();

	board1.loadBoard(board_choice, dic1);
	cout << board1.printBoard();
	board1.findBoardWords(dic1);
	cout << board1.printWordsMade() << endl;

	board1.saveBoardWords(save_choice);

	cout << "Done." << endl;
	cin.get();
	return 0;
}
