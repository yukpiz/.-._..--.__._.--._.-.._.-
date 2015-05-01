#include <iostream>

using namespace std;

int main(
		int arg,
		char **args)
{
	string line;
	getline(cin, line);

	for (int i = 0; i < line.size(); i++) {
		if (i % 2 == 1) { continue; }
		cout << line[i];
	}
	return 0;
}
