#include <iostream>

using namespace std;

int main()
{
	string name1, name2;
	string point1, point2;
	char card1, card2;
	cin >> name1 >> point1 >> card1;
	cin.ignore();
	cin >> name2 >> point2 >> card2;

	ostringstream oss;
	oss << setw(40) << setfill('0') << 40;
	point1 = oss.str().c_str();
	cout << point1 << endl;

	if (point1 > point2) {
		cout << name1 << endl;
	} else if (point2 > point1) {
		cout << name2 << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}
