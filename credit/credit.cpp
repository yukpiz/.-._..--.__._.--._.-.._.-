#include <iostream>
#include <vector>

using namespace std;

int calc(
	int num)
{
	while (1) {
		string numstr = to_string(num);
		if (numstr.size() == 1) { return stoi(numstr); }
		num = ((int)numstr[0] - '0') + ((int)numstr[1] - '0');
	}
}

int genX(
	string number)
{
	int even = 0, odd = 0;
	for (int i = number.size() - 1; i >= 0; i--) {
		if (number[i] == 'X') { continue; }
		if (i % 2 == 0) {
			int twice = ((int)number[i] - '0') * 2;
			even += calc(twice);
		} else {
			odd += (int)number[i] - '0';
		}
	}

	string sumstr = to_string(even + odd);
	int first = ((int)sumstr[sumstr.size() - 1] - '0');
	return first == 0 ? first : 10 - first;
}

int main(
	int arg,
	char **args)
{
	int count;
	cin >> count;
	cin.ignore();

	vector<string> numbers;
	for (int i = 0; i < count; i++) {
		string line;
		getline(cin, line);
		numbers.push_back(line);
	}

	for (int i = 0; i < numbers.size(); i++) {
		cout << genX(numbers[i]) << endl;
	}
}
