/*
 * [Compile]
 *   g++ -std=c++11 string.cpp -o string
 */

#include <iostream>

using namespace std;

int main(
		int arg,
		char **args)
{
	string a, b;
	cin >> a >> b;

	string line;
	cin >> line;

	int start = 0, end = 0;
	while (1) {
		int st = line.find(a, start);
		start = st == -1 ? -1 : st + a.size();
		end = line.find(b, end);
		if (start == -1) { break; }
		string output = line.substr(start, end - start);
		output = output.size() == 0 ? "<blank>" : output;
		cout << output << endl;
		end += b.size();
	}
}
