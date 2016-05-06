#include <iostream>
#include <vector>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <time.h>
using namespace std;

template<typename T>
T maxInMap(const unordered_map<T, int>& myMap)
{
	T result;
	int maxCount = INT_MIN;
	for (auto iter = myMap.begin(); iter != myMap.end(); iter++) {
		// debug
		cout << iter->first << ": " << iter->second << endl;
		if (iter->second > maxCount) {
			maxCount = iter->second;
			result = iter->first;
		}
	}
	return result;
}

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

string getNewStateForWord(const string& word, char guess, const string& state)
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

string getNewState(char guess, const string& state, vector<string>& words)
{
	unordered_map<string, int> counts;
	unordered_map<string, vector<string> > patterns;
	for (int i = 0; i < words.size(); i++) {
		string candidate = words[i];
		if (candidate.length() == state.length()) {
			string nextState = getNewStateForWord(candidate, guess, state);
			counts[nextState]++;
			patterns[nextState].push_back(candidate);
		}
	}

	string maxState = maxInMap(counts);

	words.clear();
	for (int i = 0; i < patterns[maxState].size(); i++) {
		words.push_back(patterns[maxState][i]);
	}

	// debug
	cout << words.size() << endl;

	return maxState;
}

int main()
{
	srand(time(NULL));
	vector<string> words;
	getWords(words);
	int length = rand() % 3 + 5;

	string state = "";
	for (int i = 0; i < length; i++) {
		state += "-";
	}

	unordered_set<char> guessed;

	int guesses = 10;
	while (guesses > 0) {
		cout << "You have " << guesses << " guesses left." << endl;
		cout << state << endl;
		char guess = getGuess(guessed);
		string newState = getNewState(guess, state, words);
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
	cout << "The word was: " << words[0] << endl;
}
