/*
 * [Compile]
 *   g++ -std=c++11 rpg.cpp -o rpg
 */

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

void inputLog(
		int &width,
		int &height,
		int &pos_x,
		int &pos_y,
		vector< tuple<char, int> > &logs)
{
	int count;
	cin >> width >> height >> count;
	cin >> pos_x >> pos_y;

	char dir;
	int step;
	for (int i = 0; i < count; i++) {
		cin >> dir >> step;
		tuple<char, int> t = tuple<char, int>(dir, step);
		logs.push_back(t);
	}
}

void stepLog(
		int &width,
		int &height,
		int &pos_x,
		int &pos_y,
		tuple<char, int> log)
{
	char dir = get<0>(log);
	int step = get<1>(log);

	switch (dir) {
		case 'U':
			step = (step + pos_y) % height;
			pos_y += step;
			break;
		case 'D':
			step = (step + pos_y) % height;
			pos_y -= step;
			break;
		case 'L':
			step = (step + pos_x) % width;
			pos_x -= step;
			break;
		case 'R':
			step = (step + pos_x) % width;
			pos_x += step;
			break;
	}
}

void traceLogs(
		int &width,
		int &height,
		int &pos_x,
		int &pos_y,
		vector< tuple<char, int> > &logs)
{
	cout << "LOGS COUNT:" << logs.size() << endl;
	for (int i = 0; i < logs.size(); i++) {
		stepLog(width, height, pos_x, pos_y, logs[i]);
	}
}

int main(
		int arg,
		char **argv)
{
	int w, h, x, y;
	vector< tuple<char, int> > logs;
	inputLog(w, h, x, y, logs);

	traceLogs(w, h, x, y, logs);
	cout << "CURRENT:" << x << "," << y << endl;
}
