/*
 * [Compile]
 *   g++ -std=c++11 price.cpp -o price
 */

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(
		int arg,
		char **args)
{
	int a, b, r;
	cin >> a >> b >> r;

	int count;
	cin >> count;

	vector< vector<int> > points;
	for (int i = 0; i < count; i++) {
		int x, y;
		cin >> x >> y;
		vector<int> point{x, y};
		points.push_back(point);
	}

	for (int i = 0; i < points.size(); i++) {
		string answer;
		answer = pow(points[i][0] - a, 2) + pow(points[i][1] - b, 2) >= pow(r, 2) ? "silent" : "noisy";
		cout << answer << endl;
	}

	return 0;
}
