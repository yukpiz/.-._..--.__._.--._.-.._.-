#include <iostream>
#include <vector>

using namespace std;

class TurretDefense
{
	public:
		int firstMiss(
			vector<int> xs,
			vector<int> ys,
			vector<int> times);
};

int TurretDefense::firstMiss(
	vector<int> xs,
	vector<int> ys,
	vector<int> times)
{
	int xpoint = 0, ypoint = 0, curtime = 0, buffer = 0, limit = 0;
	for (int i = 0; i < xs.size(); i++) {
		int xtarget = xs[i], ytarget = ys[i];
		limit = times[i] - curtime;
		int exec = abs(xtarget - xpoint) + abs(ytarget - ypoint);
		xpoint = xtarget;
		ypoint = ytarget;
		buffer = limit - exec < 0 ? 0 : limit - exec;
		if (limit - exec < 0) { return i; }
		curtime = times[i];
// 		cout << "limit:" << limit << "s" << endl;
// 		cout << "exec:" << exec << "s" << endl;
// 		cout << "buffer:" << buffer << "s" << endl;
// 		cout << "curtime:" << curtime << "s" << endl;
// 		cout << endl;
	}
	return -1;
}

int main(
	int arg,
	char **args)
{
	TurretDefense *defense;
	cout << defense->firstMiss({3, 5, 6}, {7, 5, 6}, {11, 15, 16}) << endl;
	cout << defense->firstMiss({1,2,3,4,15}, {1,2,3,4,15}, {100,200,300,400,405}) << endl;
	cout << defense->firstMiss({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16}, {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16}, {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,31}) << endl;
	cout << defense->firstMiss({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16}, {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16}, {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32}) << endl;
	return 0;
}
