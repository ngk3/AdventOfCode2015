#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// cl /EHsc Star1.cpp

// Function that gets the end floor of Santa
int getFloor(string filename) {
	int counter = 0;
	
	// Open the file and go through each elevator movement
	ifstream f(filename);
	if (f.is_open()) {
		string line;
		getline(f, line);
		for (char&c : line) {
			if (c == '(')
				counter++;
			else if (c == ')')
				counter--;
		}
		f.close();
	}
	return counter;
}

int main() {
	cout << "Santa is at floor " << getFloor("Star1_input.txt") << endl;
}