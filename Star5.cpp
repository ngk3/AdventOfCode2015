#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

using namespace std;

// Function that gets the number of houses with at least one present given a list of instructions in the file filename
int getNumHouseWithAtLeastOnePresent(string filename) {
	// Store each coordinate visited in a set
	int x = 0;
	int y = 0;
	unordered_set<string> visited;

	visited.insert(to_string(x) + "," + to_string(y));

	// Open the file and add each coordinate (if not existing already) into visited
	ifstream f(filename);
	if (f.is_open()) {
		string line;
		getline(f, line);
		for (char& c : line) {
			if (c == '^')
				y += 1;
			else if (c == 'v')
				y -= 1;
			else if (c == '>')
				x += 1;
			else
				x -= 1;
			visited.insert(to_string(x) + "," + to_string(y));
		}
		f.close();
	}

	// Return the size of the set which is equal to the number of houses with at least one present
	return visited.size();
}

int main() {
	cout << "Number of houses with at least one present = " << getNumHouseWithAtLeastOnePresent("Star5_input.txt") << endl;
}