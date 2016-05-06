#include <iostream>
#include <vector>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <time.h>
using namespace std;

void getWords(vector<string>& words)
{
	ifstream input("dictionary.txt");
	while (true) {
		string next;
		input >> next;
		if (input.fail()) break;
		words.push_back(next);
	}
}

char getGuess(unordered_set<char>& guessed)
{
	while (true) {
		cout << "Enter a guess: ";
		string next;
		getline(cin, next);
		if (next.length() == 1 &&
			next[0] >= 'a' &&
			next[0] <= 'z' &&
		    guessed.find(next[0]) == guessed.end()) {
			
			guessed.insert(next[0]);
			return next[0];
		}

		cout << "You must enter a single, lowercase"
		     << " character that you haven't guessed"
			 << " yet." << endl;
	}
	
}

string getNewState(const string& word, char guess, const string& state)
{
	string result = "";
	for (int i = 0; i < word.length(); i++) {
		if (word[i] == guess) {
			result += guess;
		} else {
			result += state[i];
		}
	}

	return result;
}

int main()
{
	srand(time(NULL));
	vector<string> words;
	getWords(words);

	string word = words[rand() % words.size()];

	// debug
	cout << word << endl;
	string state = "";
	for (int i = 0; i < word.length(); i++) {
		state += "-";
	}

	unordered_set<char> guessed;

	int guesses = 10;
	while (guesses > 0) {
		cout << "You have " << guesses << " guesses left." << endl;
		cout << state << endl;
		char guess = getGuess(guessed);
		string newState = getNewState(word, guess, state);
		if (newState == state) {
			cout << "Nope!" << endl;
			guesses--;
		} else {
			cout << "Yup!" << endl;
			state = newState;
			if (state.find('-') == string::npos) {
				cout << "You win!" << endl;
				exit(0);
			}
		}
	}

	cout << "You lose!" << endl;
	cout << "The word was: " << word << endl;
}
