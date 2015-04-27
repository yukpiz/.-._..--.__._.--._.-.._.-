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
	return 0;
}

int main(
	int arg,
	char **args)
{
	TurretDefense *defense;
	cout << defense->firstMiss({1}, {2}, {3}) << endl;
	return 0;
}
