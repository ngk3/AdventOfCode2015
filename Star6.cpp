#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

using namespace std;

// Function that gets the number of houses with at least one present given a list of instructions in the file filename
int getNumHouseWithAtLeastOnePresent(string filename) {
	// Store each coordinate visited in a set
	int santa_x = 0;
	int santa_y = 0;

	int robo_x = 0;
	int robo_y = 0;
	unordered_set<string> visited;
	
	visited.insert(to_string(santa_x) + "," + to_string(santa_y));

	// Open the file and add each coordinate (if not existing already) into visited, alternating between santa and robo-santa
	ifstream f(filename);
	if (f.is_open()) {
		string line;
		getline(f, line);
		bool santa_turn = true;
		for (char& c : line) {
			if (santa_turn) {
				if (c == '^')
					santa_y += 1;
				else if (c == 'v')
					santa_y -= 1;
				else if (c == '>')
					santa_x += 1;
				else
					santa_x -= 1;
				visited.insert(to_string(santa_x) + "," + to_string(santa_y));
				santa_turn = false;
			}
			else {
				if (c == '^')
					robo_y += 1;
				else if (c == 'v')
					robo_y -= 1;
				else if (c == '>')
					robo_x += 1;
				else
					robo_x -= 1;
				visited.insert(to_string(robo_x) + "," + to_string(robo_y));
				santa_turn = true;
			}
		}
		f.close();
	}

	// Return the size of the set which is equal to the number of houses with at least one present
	return visited.size();
}

int main() {
	cout << "Number of houses with at least one present = " << getNumHouseWithAtLeastOnePresent("Star5_input.txt") << endl;
}