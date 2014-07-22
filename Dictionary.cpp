#include "Dictionary.h"


// CONSTRUCTORS
Dictionary::Dictionary(){}
Dictionary::~Dictionary(){}

// ANALYZERS
/* Checks to see if a word is in the dictionary. */
bool Dictionary::findWord(string word_query)
{
	bool is_word = false;

	if (dictionary_words.count(word_query) != 0)
	{
		is_word = true;
	}

	return is_word;
}

/*  */
bool Dictionary::findPrefix(string word_query)
{
	bool is_prefix = false;
	int query_length = word_query.size();
	
	std::set<string>::iterator itlow;
	itlow = dictionary_words.lower_bound(word_query);
	
	if(itlow != dictionary_words.end())
	{
		string closest_prefix = *itlow;
	
		if (closest_prefix.substr(0, query_length) == word_query)
		{
			//cout << closest_prefix << " found with " << closest_prefix.substr(0, 2) << endl;
			//cout << << endl;
			is_prefix = true;
		}
	}
	
	return is_prefix;
}

// EXPORTERS
/*  */
/*  */

// IMPORTERS
int Dictionary::getFileLines(string file_choice)
{
	ifstream in_file;
	in_file.open(file_choice);
	int line_count = 0;

	do
	{
		line_count++;
	} while (!getline(in_file, file_choice).fail());

	line_count--;

	return line_count;
}

/* Loads a text file and adds the words of that file to a map called document_index. */
bool Dictionary::loadDictionary(string document_choice)
{
	bool is_working = false;
	ifstream in_file;
	string file_choice = document_choice;

	cout << "File name to load: \t" << file_choice << endl;
	//cin >> file_choice;
	in_file.open(file_choice);

	int line_count = 0;
	line_count = getFileLines(file_choice);
	//cout << line_count << endl;

	if (hasLines(line_count) == false)
	{
		return is_working;
	}
	else
	{
		for (int i = line_count; i > 0; i--)
		{
			string word_in, word_lowercase = "";
			int line_in = 0;

			getline(in_file, word_in);
			word_lowercase = convert_lowercase(word_in);
			//cout << "New word: " << word_lowercase << " added to set." << endl;
			dictionary_words.insert(word_lowercase);
		}
		is_working = true;
	}

	cout << endl;

	return is_working;
}

/*  */

// MUTATORS
/* Converts words in the dictionary to lowercase letters. */
string Dictionary::convert_lowercase(string word_in)
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
/* Prints the Dictionary Set */
void Dictionary::printDictionary()
{
	set<string>::iterator iter;
	int index = 0;
	cout << "Dictionary contains: " << endl;
	cout << "Size = " << dictionary_words.size() << endl;
	for (iter = dictionary_words.begin(); iter != dictionary_words.end(); iter++)
	{
		cout << (*iter) << endl;
		index++;
		//cout << index << endl;
	}
	cout << endl;
}

/*  */


// VALIDATORS
/*  */
bool Dictionary::hasLines(int line_count)
{
	bool has_lines = false;
	if (line_count == 0)
	{
		cout << "This is an empty file." << endl;
	}
	else
	{
		has_lines = true;
	}
	return has_lines;
}
