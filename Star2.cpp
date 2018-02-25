#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function that gets the first basement movement for Santa
int getFirstBasementMovement(string filename) {
	int counter = 0;

	// Open the file and keep moving until basement is found
	ifstream f(filename);
	if (f.is_open()) {
		string line;
		int first_touch = 0;
		getline(f, line);
		for (char&c : line) {
			first_touch++;
			if (c == '(')
				counter++;
			else if (c == ')')
				counter--;
			if (counter == -1)
				return first_touch;
		}
		f.close();
	}
}

int main() {
	cout << "Santa goes to basement at instruction " << getFirstBasementMovement("Star1_input.txt") << endl;
}