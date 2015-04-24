#include <iostream>
#include <vector>

using namespace std;

vector<int> timeSub(
	vector<int> &hm,
	int dm)
{
	vector<int> timeZero {24, 0};
	int min = hm[0] * 60 + hm[1];
	int diff = min - dm;
	if (diff < 0) { return timeSub(timeZero, diff * -1); }
	return {diff / 60, diff % 60};
}

bool timeMax(
	vector<int> x,
	vector<int> y)
{
	if (x[0] > y[0]) {
		return true;
	} else if (x[0] < y[0]) {
		return false;
	} else if (x[1] >= y[1]) {
		return true;
	} else {
		return false;
	}
}

int prevTrain(
	vector< vector<int> > &times,
	vector<int> &startLimit)
{
	for (int i = times.size() - 1; i >= 0; i--) {
		if (timeMax(startLimit, times[i])) { return i; }
	}
	return -1;
}

void printTime(
	vector<int> time)
{
	printf("%02d:%02d\n", time[0], time[1]);
}

int main(
	int arg,
	char **args)
{
	vector<int> limit{8, 59};

	int a, b, c;
	cin >> a >> b >> c;
	cin.ignore();

	int n;
	cin >> n;
	cin.ignore();

	vector< vector<int> > times;
	for (int i = 0; i < n; i++) {
		int h, m;
		cin >> h >> m;
		cin.ignore();
		vector<int> time{h, m};
		times.push_back(time);
	}

	vector<int> paiza = timeSub(limit, b + c);
	vector<int> prev = times[prevTrain(times, paiza)];
	vector<int> start = timeSub(prev, a);
	printTime(start);
}
