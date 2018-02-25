#include <iostream>
#include "md5.h"
#include <string>
#include <regex>

using namespace std;

// Function used to find the first positive number that combines with the hash that starts with 5 zeros
int getAdventCoinHackNum(string hash) {
	int counter = 0;
	while (true) {
		// Get the hash and return counter if md5 hash returns a beginning with 5 zeros
		string result = md5(hash + to_string(counter));

		if (regex_match(result, regex("^00000(.)+"))) 
			return counter;
		
		counter++;
	}
}

int main(int argc, char *argv[]) {
	cout << "Lowest positive number for a hash for AdventCoins = " << getAdventCoinHackNum("bgvyzdsv") << endl;
}