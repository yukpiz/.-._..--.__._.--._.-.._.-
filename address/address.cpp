/*
 * [Compile]
 *   g++ -std=c++11 address.cpp -o address
 */

#include <iostream>
#include <regex>
#include <vector>

using namespace std;

void inputAddress(
		vector<string> &addresses)
{
	int count;
	cin >> count;
	cin.ignore();

	for (int i = 0; i < count; i++) {
		string line;
		getline(cin, line);
		addresses.push_back(line);
	}
}

void matchAddress(
		vector<string> &addresses,
		vector<string> &results)
{
	try {
		regex re("\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}");
		for (int i = 0; i < addresses.size(); i++) {
			string result = regex_match(addresses[i], re) ? "True" : "False";
			results.push_back(result);
		}
	} catch (const regex_error& err) {
		cout << err.code() << ":" << err.what() << endl;
	}
}

void coutVector(
		vector<string> v)
{
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}

int main(
		int arg,
		char **args)
{
	vector<string> addresses;
	inputAddress(addresses); //Input IPv4 addresses.

	vector<string> results;
	matchAddress(addresses, results); //Pattern match of addresses.

	coutVector(results); //Output result of match.
	return 0;
}
