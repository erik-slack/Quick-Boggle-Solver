#include "Board.h"

// CONSTRUCTORS
Board::Board(){}
Board::~Board(){}

// ANALYZERS
/* Finds all valid words you can possibly make on the board. */
void Board::findBoardWords(Dictionary& dic1)
{
	int board_length = board_cols.size();
	
	for (int i = 0; i < board_length; i++)
	{
		for (int j = 0; j < board_length; j++)
		{
			vector<int> times_used;
			for (int k = 0; k < board_length * board_length; k++)
			{
				times_used.push_back(0);
			}

			vector<string> temp_cols = board_cols[i];
			string word_so_far = "";
			makeWord(word_so_far, j, i, times_used, dic1);
			//cout << j << " --- " << i << endl;
		}
		//cout << "x---x" << endl;
	}
}

/* Indentifies one word at a time. */
void Board::makeWord(string word_so_far, int col, int row, vector<int> times_used, Dictionary& dic1)
{
	int board_length = board_cols.size();

	if (row < 0 || row > board_length - 1 || col < 0 || col > board_length - 1){ return; }
	(times_used[row * board_length + col])++;
	if (times_used[row * board_length + col] >= 2){ return; }

	//int query_length = word_so_far.size();

	if (word_so_far.size() >= 2)
	{
		if (dic1.findPrefix(word_so_far) != true){ return; }
	}
	
	vector<string> temp_cols = board_cols[row];
	word_so_far = word_so_far + temp_cols[col];
	//cout << word_so_far << endl;

	if (consultDictionary(word_so_far, dic1) == true && word_so_far.size() != 3)
	{
		words_made.insert(word_so_far);
	}

	makeWord(word_so_far, col - 1, row - 1, times_used, dic1);
	makeWord(word_so_far, col, row - 1, times_used, dic1);
	makeWord(word_so_far, col + 1, row - 1, times_used, dic1);
	makeWord(word_so_far, col - 1, row, times_used, dic1);
	makeWord(word_so_far, col + 1, row, times_used, dic1);
	makeWord(word_so_far, col - 1, row + 1, times_used, dic1);
	makeWord(word_so_far, col, row + 1, times_used, dic1);
	makeWord(word_so_far, col + 1, row + 1, times_used, dic1);
}

bool Board::consultDictionary(string word_query, Dictionary& dic1)
{
	bool is_prefix = false;

	if (dic1.findWord(word_query) == true)
	{
		is_prefix = true;
	}

	return is_prefix;
}

// EXPORTERS
/*  */
void Board::saveBoardWords(string save_choice)
{
	ofstream out_file;
	string file_choice = save_choice;

	out_file.open(file_choice);
	out_file << printBoard();
	out_file << printWordsMade();
}

/*  */

// IMPORTERS
/* This function assists the Load Functions with knowing how many times to iterate the getline() functions by prereading the file. */
int Board::getFileLetters(string file_choice)
{
	ifstream in_file;
	in_file.open(file_choice);
	int letter_count = 0;
	string temp_letter;

	do
	{
		in_file >> temp_letter;
		letter_count++;
		//cout << letter_count << endl;
	} while (!in_file.fail());

	letter_count--;
	cout << "File letters: " << letter_count << endl;
	return letter_count;
}

///* Loads a text file and adds the Board words of that file to a map called found_words. */
bool Board::loadBoard(string board_choice, Dictionary& dictionary_choice)
{
	bool is_working = true;
	ifstream in_file;
	string file_choice = board_choice;

	cout << "File name to load: \t" << file_choice << endl;
	//cin >> file_choice;
	in_file.open(file_choice);

	int letter_count = 0;
	letter_count = getFileLetters(file_choice);

	if (hasLetters(letter_count) == false)
	{
		is_working = false;
		return is_working;
	}
	else
	{
		//for (int i = letter_count; i > 0; i = i--)
		//stringstream s;
		int board_length = sqrt(letter_count);
		string letter_in, letter_lowercase = "";

		for (int i = letter_count; i > 0; i = i - board_length)
		{
			vector<string> row;

			for (int j = 0; j < board_length; j++)
			{
				in_file >> letter_in;
				cout << "Letter: " << letter_in << endl;
				letter_lowercase = convert_lowercase(letter_in);				
				row.push_back(letter_lowercase);				
			}

			board_cols.push_back(row);
		}

		//s.clear();
		//is_working = true;
	}

	cout << endl;

	return is_working;
}

// MUTATORS
/* Converts words in the Board to lowercase letters. */
string Board::convert_lowercase(string word_in)
{
	string word_out = word_in;

	for (int i = 0; i < word_out.length(); i++)
	{
		if (isalpha(word_out[i]) == false)
		{
			word_out[i] = word_out[i + 1];
			string temp_word;
			temp_word = word_out.substr(0, word_out.length() - 1);
			word_out = temp_word;
		}
		else
		{
			word_out[i] = tolower(word_out[i]);
		}
	}

	return word_out;
}

/*  */

// PRINTERS
/*  */
string Board::printBoard()
{
	stringstream ss;
	int board_length = board_cols.size();

	for (int i = 0; i < board_length; i++)
	{
		for (int j = 0; j < board_length; j++)
		{
			vector<string> temp_row = board_cols[i];
			//ss << "( " << i << ", " << j << " )";
			ss << (temp_row[j]);
			if (j != board_length - 1)
			{
				ss << " ";
			}
		}
		ss << endl;
	}
	ss << endl;
	cout << endl;
	return ss.str();
}

string Board::printWordsMade()
{
	stringstream ss;

	set<string>::iterator iter;
	int index = 0;
	//ss << "Words That Were Made: " << endl;
	//ss << "Size = " << words_made.size() << endl;
	
	for (iter = words_made.begin(); iter != words_made.end(); iter++)
	{
		ss << (*iter) << endl;
		index++;
		//ss << index << endl;
	}

	return ss.str();

}

/*  */

// VALIDATORS
/* Tells whether a board file is empty or not. */
bool Board::hasLetters(int letter_count)
{
	bool has_letters = false;
	if (letter_count == 0)
	{
		cout << "This is an empty file." << endl;
	}
	else
	{
		has_letters = true;
	}
	return has_letters;
}

//bool Board::hasLines(int line_count)
//{
//	bool has_lines = false;
//	if (line_count == 0)
//	{
//		cout << "This is an empty file." << endl;
//	}
//	else
//	{
//		has_lines = true;
//	}
//	return has_lines;
//}

/* Finds out if the word is already in the dictionary or not. */
bool Board::checkValidWord(string word_in, Dictionary& dictionary_choice)
{
	bool is_valid = false;
	string word_to_check = word_in;

	if (dictionary_choice.findWord(word_to_check) == true)
	{
		is_valid = true;
	}

	return is_valid;
}


/*  */
