/*
 * [Compile]
 *   g++ -std=c++11 upper.cpp -o upper
 */

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(
		int arg,
		char **args)
{
	string line;
	getline(cin, line);

	transform(line.begin(), line.end(), line.begin(), ::toupper);
	cout << line << endl;
}
