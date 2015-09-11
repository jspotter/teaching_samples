#include <cstdlib>
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	string line;
	stringstream ss;
	
	getline(cin, line);

	ss << line;
	while (true) {
		string next;

		// Get whatever is between the last space
		// character we saw and the next space character.
		// (Or, if we're at the beginning, get whatever
		// is before the first space character. If we're
		// near the end and there are no spaces left,
		// get the rest of the stringstream's contents.)
		getline(ss, next, ' ');
		if (ss.fail()) break;
	
		// If the input contains multiple consecutive spaces,
		// getline can put a zero-length string in next!
		// (This is because there is technically an empty
		// string between two consecutive spaces.) This
		// length check ensures that we only have to care
		// about next if it contains an actual word.
		//
		// TRY: Removing the check (just lines 34 and 36)
		// and typing "I ate     cereal for   breakfast"
		// (with the spaces). See what happens. Then add
		// the check back in, and type the same thing.
		if (next.length() > 0) {
			cout << next << endl;
		}
	}

	return 0;
}

