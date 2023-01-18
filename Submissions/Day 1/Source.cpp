// 18.01.2023 - 8054757 - Matvei Maslov
// Question 2
#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Symbol
{
private:
	int ascii_code;
public:
	Symbol()
	{
		ascii_code = 0;
	}
	Symbol(char symbol)
	{
		for (int i = 0; i < 128; ++i)
		{
			char sym = i;
			if (sym == symbol)
			{
				ascii_code = i;
				break;
			}
		}
	}
	char back_to_symbol()
	{
		for (char i = NULL; i != '~'; ++i)
		{
			if ((int)i == ascii_code)
			{
				return i;
				break;
			}
		}
		return NULL;
	}
};

class Word
{
private:
	Symbol** symbols;
	size_t length;
public:
	Word()
	{
		length = 0;
		symbols = NULL;
	}
	Word(string word)
	{
		length = word.size();
		symbols = new Symbol*[length];
		for (int i = 0; i < length; ++i) symbols[i] = new Symbol(word[i]);
	}
	string back_to_string()
	{
		string word = "";
		for (int i = 0; i < length; ++i) word += symbols[i]->back_to_symbol();
		return word;
	}
	~Word()
	{
		delete[] symbols;
	}
};

class Phrase
{
private:
	queue<Word*>* words;
public:
	Phrase()
	{
		words = NULL;
	}
	Phrase(string phrase)
	{
		words = new queue<Word*>;
		string word;
		char curr_sym;
		for (int i = 0; i<=phrase.size(); ++i)
		{
			curr_sym = phrase[i];
			if (curr_sym == ' ' || curr_sym == '\0')
			{
				if (word.size()!=0) words->push(new Word(word));
				word = "";
				continue;
			}
			word += curr_sym;
		}

	}
	void print_phrase()
	{
		if (words == NULL || words->size() == 0) return;
		cout << words->front()->back_to_string();
		words->pop();
		while (words->size()!=0)
		{
			cout << ' ' << words->front()->back_to_string();
			words->pop();
		}
		cout << endl;
	}
};


int main()
{
	Phrase phrase("hello world!");
	phrase.print_phrase();
	return 0;
}