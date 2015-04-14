/*
 * [Compile]
 *   g++ -std=c++11 ball.cpp -o ball
 */

#include <vector>
#include <iostream>

using namespace std;

int default_input(
		int &diameter,
		vector< vector<int> > &sizes)
{
	int count;
	cin >> count >> diameter;
	diameter *= 2;

	for (int i = 0; i < count; i++) {
		int h, w, d;
		cin >> h >> w >> d;
		sizes.push_back({h, w, d});
	}
}

int main(
	int arg,
	char **args)
{
	vector < vector<int> > sizes;
	int diameter;
	default_input(diameter, sizes);

	for (int i = 0; i < sizes.size(); i++) {
		int h = sizes[i][0];
		int w = sizes[i][1];
		int d = sizes[i][2];
		bool breakflg = h < diameter|| w < diameter || d < diameter ? true : false;
		if (!breakflg) {
			cout << i + 1 << endl;
		}
	}
	return 0;
}


