#pragma once
#include <iostream>
#include <map>
#include <cmath>
#include <cctype>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include "Dictionary.h"
using namespace std;


class Board
{
private:
	// DATA
	/*COL*/vector</*ROW*/vector<string>> board_cols;
	set<string> words_made;

public:
	// CONSTRUCTORS
	Board();
	~Board();

	// ANALYZERS
	/*  */
	void findBoardWords(Dictionary& dic1);
	/* Indentifies one word at a time. */
	void makeWord(string word_so_far, int row, int col, vector<int> times_used, Dictionary& dic1);
	bool consultDictionary(string word_query, Dictionary& dic1);
	/*  */

	// EXPORTERS
	/*  */
	void saveBoardWords(string save_choice);
	/*  */

	// IMPORTERS
	int getFileLetters(string file_choice);
	///* Imports command line argument #1 and makes each 4 lines into a student in the all_students vector. */
	bool loadBoard(string board_choice, Dictionary& dictionary_choice);
	///*  */
	//int getFileLines(string file_choice);

	// MUTATORS
	/* Converts words in the board to lowercase letters. */
	string convert_lowercase(string word_in);
	/*  */

	// PRINTERS
	/*  */
	string printBoard();
	/*  */
	string printWordsMade();

	// VALIDATORS
	/*  */
	bool hasLetters(int letter_count);
	bool hasLines(int line_count);
	/* Finds out if the word is already in the dictionary or not. */
	bool checkValidWord(string word_in, Dictionary& dictionary_choice);
	/*  */
};
