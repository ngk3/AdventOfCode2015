#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int getFloor(string filename) {
	int counter = 0;
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