#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// Function that splits the string s by delimiter and translate to ints
vector<int> split_int(const string& s, char delimiter) {
	string token;
	istringstream tokenstream(s);
	vector<int> tokens;
	while (getline(tokenstream, token, delimiter))
		tokens.push_back(stoi(token));
	return tokens;
}

// Function that gets the total ribbon needed for all the presents
int getTotalRibbonNeeded(string filename) {
	int total = 0;

	// Run through the file
	ifstream f(filename);
	if (f.is_open()) {
		string line;
		while (getline(f, line)) {
			// sort the vector so the smallest side is at index 0 and index 1
			vector<int> line_splitted = split_int(line, 'x');
			sort(line_splitted.begin(), line_splitted.end());
			total += (2 * line_splitted[0]) + (2 * line_splitted[1]) + (line_splitted[0] * line_splitted[1] * line_splitted[2]);
		}
		f.close();
	}
	return total;
}

int main() {
	cout << "Total ribbon needed = " << getTotalRibbonNeeded("Star3_input.txt") << " feet" << endl;
}