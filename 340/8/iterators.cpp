#include <cstdlib>
#include <iostream>
#include <algorithm>       // for sort and transform
#include <map>
#include <unordered_map>
#include <set>
#include <utility>         // for pair
using namespace std;

static const string cs_string = "CSC 340 is the best class in the worlddddd";

void iterate_over_map()
{
	map<string, int> m;
	m.insert(pair<string, int>("red", 3));
	m.insert(pair<string, int>("blue", 16));
	m.insert(pair<string, int>("yellow", 10));

	map<string, int>::iterator iter;
	for (iter = m.begin(); iter != m.end(); iter++) {
		cout << iter->first << ": " << iter->second << endl;
	}
}

void iterate_over_unordered_map()
{
	// Note the similarity to the code above!

	unordered_map<string, int> m;            // this line is different
	m.insert(pair<string, int>("red", 3));
	m.insert(pair<string, int>("blue", 16));
	m.insert(pair<string, int>("yellow", 10));

	unordered_map<string, int>::iterator iter;    // so is this line
	for (iter = m.begin(); iter != m.end(); iter++) {
		cout << iter->first << ": " << iter->second << endl;
	}
}

void iterate_over_set()
{
	set<string> my_set;
	my_set.insert("red");
	my_set.insert("blue");
	my_set.insert("yellow");
	my_set.insert("blue");    // ignored! blue is already in the set

	set<string>::iterator iter;
	for (iter = my_set.begin(); iter != my_set.end(); iter++) {
		cout << *iter << endl;
	}
}

void sort_a_string()
{
	string s(cs_string);
	sort(s.begin(), s.end());

	cout << "sorted string: " << s << endl;
}

void capitalize_a_string()
{
	string s(cs_string);

	// Arguments:
	//
	// Where do I start? s.begin()!
	// Where do I finish? s.end()!
	// Where do I put the result? s.begin()!
	// What do I do to each letter? ::toupper!
	transform(s.begin(), s.end(), s.begin(), [] (char c) -> char {
		if (c >= 'a' && c <= 'z') {
			return c - 'a' + 'A';
		}

		return c;
	});

	cout << "capitalized string: " << s << endl;
}

int main()
{
	cout << "Iterate over map" << endl << "-----" << endl;
	iterate_over_map();
	cout << endl << "Iterate over unordered map" << endl << "-----" << endl;
	iterate_over_unordered_map();
	cout << endl << "Iterate over set" << endl << "-----" << endl;
	iterate_over_set();

	cout << endl << "Sort a string" << endl << "-----" << endl;
	sort_a_string();
	cout << endl << "Capitalize a string" << endl << "-----" << endl;
	capitalize_a_string();

	return 0;
}

