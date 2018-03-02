#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

// Function that checks if the string has two pairs that do not overlap each other (e.g. "xyxy", "baqilba", not "aaa")
bool hasTwoPairsNonOverlap(string input) {
	if (regex_search(input, regex("(.)(.).*\\1\\2")))
		return true;
	return false;
}

// Function that checks if the string has at least one letter which repeats with exactly one letter between them. (e.g. "xyx")
bool hasABA(string input) {
	if (regex_search(input, regex("(.).\\1")))
		return true;
	return false;
}

// Function that opens the file filename and counts the number of "nice" strings found and return this number
int countNiceStrings(string filename) {
	int counter = 0;
	ifstream f(filename);
	string line;

	if (f.is_open()) {
		while (getline(f, line)) {
			if (hasABA(line) && hasTwoPairsNonOverlap(line))
				counter++;
		}
		f.close();
	}
	return counter;
}

int main() {
	cout << "Number of nice strings = " << countNiceStrings("Star9_input.txt") << endl;
}