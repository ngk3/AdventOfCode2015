#include "utilities.h"

using namespace std;

vector<string> split(string str, string del) {
	vector<string> returning;
	int begin = 0;
	while (begin < str.size()) {
		int end = begin;
		while (str[end] != del[0]) {
			if (end == str.size())
				break;
			end++;
		}
		if (begin != end)
			returning.push_back(str.substr(begin, end - begin));
		begin = end + 1;
	}

	if (begin < str.size())
		returning.push_back(str.substr(begin, str.size() - (begin + 1)));

	return returning;
}