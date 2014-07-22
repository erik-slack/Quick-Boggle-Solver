#pragma once
#include <iostream>
#include <set>
#include <sstream>
#include <cctype>
#include <fstream>
#include <string>
using namespace std;


class Dictionary
{
private:
	// DATA
	set<string> dictionary_words;

public:
	// CONSTRUCTORS
	Dictionary();
	~Dictionary();

	// ANALYZERS
	/* Checks the dictionary to see if a word is valid according to the words stored in the dictionary. */
	bool findWord(string word_query);
	/*  */
	bool findPrefix(string word_query);

	// EXPORTERS
	/*  */
	/*  */

	// IMPORTERS

	/* Imports command line argument #2 and makes each 3 lines into a grade in the all_grades vector. */
	bool loadDictionary(string dictionary_choice);
	/* --- Tells how many lines a text file has before it is read in. */
	int getFileLines(string file_choice);

	// MUTATORS
	/* Converts words in the dictionary to lowercase letters. */
	string convert_lowercase(string word_in);
	/*  */

	// PRINTERS
	/*  */
	void printDictionary();
	/*  */


	// VALIDATORS	
	/* Checks to see if a file is empty before trying to load it. */
	bool hasLines(int line_count);
	/*  */
};
