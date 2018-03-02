#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

// Function that checks that the string does not contain "ab", "cd", "pq", or "xy"
bool notContain(string input) {
	if (regex_search(input, regex("ab")))
		return false;
	if (regex_search(input, regex("cd")))
		return false;
	if (regex_search(input, regex("pq")))
		return false;
	if (regex_search(input, regex("xy")))
		return false;
	return true;
}

// Function that checks that the string has a double letter in it (i.e. aa, baab, etc.)
bool hasDoubleLetter(string input) {
	if (regex_search(input, regex("(.)\\1")))
		return true;
	return false;
}

// Function that checks if the string has at least three vowels in it
bool hasAtLeastThreeVowels(string input) {
	int counter = 0;
	for (char& c : input) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			counter++;
		if (counter == 3)
			return true;
	}
	return false;
}

// Function that opens the file filename and counts the number of "nice" strings found and return this number
int countNiceStrings(string filename) {
	int counter = 0;
	ifstream f(filename);
	string line;

	if (f.is_open()) {
		while (getline(f, line)) {
			if (notContain(line) && hasDoubleLetter(line) && hasAtLeastThreeVowels(line)) 
				counter++;
		}
		f.close();
	}
	return counter;
}

int main() {
	cout << "Number of nice strings = " << countNiceStrings("Star9_input.txt") << endl;
}