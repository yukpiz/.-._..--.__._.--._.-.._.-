#include <iostream>
#include <string>

using namespace std;

class Substitute
{
		public:
			int getValue(string key, string code);
};

int Substitute::getValue(
	string key,
	string code)
{
	string result = "";
	for (int c = 0; c < code.size(); c++) {
		for (int k = 0; k < key.size(); k++) {
			if (code[c] == key[k]) {
				result += k == 9 ? "0" : to_string(k + 1);
			}
		}
	}
	return atoi(result.c_str());
}

int main(
	int arg,
	char **args)
{
	Substitute *substitute = new Substitute;
	cout << substitute->getValue("TRADINGFEW", "LGXWEV") << endl;;
	return 0;
}
