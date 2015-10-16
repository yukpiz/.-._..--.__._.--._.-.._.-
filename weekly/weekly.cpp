#include <iostream>
#include <vector>

using namespace std;

int main() {
	int c = 7;
	vector<string> weeks;
	for (int i = 0; i < c; i++) {
		string l;
		cin >> l;
		weeks.push_back(l);
	}

	int sum = 0;
	for (int i = 0; i < weeks.size(); i++) {
		if (weeks[i] == "no") {
			sum += 1;
		}
	}

	cout << sum << endl;
}
