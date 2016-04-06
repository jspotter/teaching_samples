#include <iostream>
using namespace std;

int countOccurrences(const string& haystack, const string& needle)
{
	if (haystack.length() == 0 || haystack.length() < needle.length()) {
		return 0;
	}

	if (haystack.substr(0, needle.length()) == needle) {
		return 1 + countOccurrences(haystack.substr(1), needle);
	} else {
		return countOccurrences(haystack.substr(1), needle);
	}
}

int main()
{
	cout << countOccurrences("hi this is a sentence", "hi") << endl;

	return 0;
}

