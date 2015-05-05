#include <iostream>
#include <vector>

using namespace std;

int main(
		int arg,
		char **args)
{
	int c;
	cin >> c;
	cin.ignore();

	vector<int> sum {0, 0, 0, 0, 0, 0, 0};
	for (int i = 0; i < c; i++) {
		int m;
		cin >> m;
		sum[i % 7] += m;
	}

	for (int i = 0; i < sum.size(); i++) {
		cout << sum[i] << endl;
	}
}
