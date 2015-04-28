#include <iostream>
#include <vector>

using namespace std;

int main(
		int arg,
		char **args)
{
	int n;
	cin >> n;
	cin.ignore();
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		cin.ignore();
		v.push_back(y - x);
	}
	int bs = v[0];
	bool ex = false;
	for (int i = 0; i < v.size(); i++) {
		ex = v[i] <= 0 or v[i] != bs ? true : false;
	}
	if (ex) {
		cout << -1 << endl;
	} else {
		cout << bs << endl;
	}
}
