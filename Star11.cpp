#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <array>
#include "utilities.h"

using namespace std;

// Function that initializes the lights from 0,0 to max_x, max_y
unordered_map<string, int> initializeLights(int max_x, int max_y) {
	unordered_map<string, int> lights;
	for (int i = 0; i <= max_x; i++) {
		for (int j = 0; j <= max_y; j++) {
			lights[to_string(i) + "," + to_string(j)] = 0;
		}
	}
	return lights;
}

// Function that reads the file filename and get the instructions
vector<array<string,3>> getInstructions(string filename) {
	ifstream f(filename);
	// Store the instrucions in an array with elem 0 = "toggle", "on", or "off", elem 1 = start coord, elem 2 end coord
	vector<array<string, 3>> instructions;
	if (f.is_open()) {
		string line;
		while (getline(f, line)) {
			vector<string> tokens = split(line, " ");
			array<string, 3> temp;
			if (tokens[0] == "toggle")
				temp = { "toggle", tokens[1], tokens[3]};
			else
				temp = { tokens[1], tokens[2], tokens[4]};
			instructions.push_back(temp);
		}
		f.close();
	}

	return instructions;
}

// Function that counts the number of on lights in lights given the maximum x and y (max_x, max_y)
int countLights(unordered_map<string, int> lights, int max_x, int max_y) {
	int count = 0;
	for (int x = 0; x <= max_x; x++) {
		for (int y = 0; y <= max_y; y++) {
			if (lights[to_string(x) + "," + to_string(y)] == 1)
				count++;
		}
	}
	return count;
}

// Function that goes through the instructions and executes each command
void perform(vector<array<string, 3>> instructions, unordered_map<string, int>& lights) {
	// Go through the instructions
	for (int i = 0; i < instructions.size(); i++) {
		// Get the top left and bottom right of the rectangle to perform the instruction
		vector<string> s1_split = split(instructions[i][1], ",");
		vector<string> s2_split = split(instructions[i][2], ",");

		// Change the light accordingly
		if (instructions[i][0] == "on") {
			for (int x = stoi(s1_split[0]); x <= stoi(s2_split[0]); x++) {
				for (int y = stoi(s1_split[1]); y <= stoi(s2_split[1]); y++) {
					lights[to_string(x) + "," + to_string(y)] = 1;
				}
			}
		}
		else if (instructions[i][0] == "off") {
			for (int x = stoi(s1_split[0]); x <= stoi(s2_split[0]); x++) {
				for (int y = stoi(s1_split[1]); y <= stoi(s2_split[1]); y++) {
					lights[to_string(x) + "," + to_string(y)] = 0;
				}
			}
		}
		else {
			for (int x = stoi(s1_split[0]); x <= stoi(s2_split[0]); x++) {
				for (int y = stoi(s1_split[1]); y <= stoi(s2_split[1]); y++) {
					if (lights[to_string(x) + "," + to_string(y)] == 0)
						lights[to_string(x) + "," + to_string(y)] = 1;
					else
						lights[to_string(x) + "," + to_string(y)] = 0;
				}
			}
		}
	}
}

int main() {
	unordered_map<string, int> lights = initializeLights(999, 999);
	vector<array<string, 3>> instructions = getInstructions("Star11_input.txt");
	perform(instructions, lights);
	cout << "Number of lights on = " << countLights(lights, 999, 999) << endl;
}