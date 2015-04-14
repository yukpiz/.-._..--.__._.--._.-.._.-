/*
 * [Compile]
 *   g++ -std=c++11 highscore.cpp -o highscore
 */

#include <iostream>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <cmath>

using namespace std;

void typeDouble(
		vector<string> &v,
		vector<double> &scores)
{
	for (int i = 0; i < v.size(); i++) {
		scores.push_back(atof(v[i].c_str()));
	}
}

void inputScores(
		vector<double> &scores)
{
	string line;
	getline(cin, line);

	vector<string> v;
	boost::algorithm::split(v, line, boost::is_space());
	typeDouble(v, scores);
}

void calcScore(
		vector<double> &scores,
		vector<double> &user,
		long &summary)
{
	double sum = 0;
	for (int i = 0; i < scores.size(); i++) {
		sum += scores[i] * user[i];
	}
	summary = roundf(sum);
}

int main(
		int arg,
		char **args)
{
	int n, m, k;
	cin >> n >> m >> k;
	cin.ignore();

	vector<double> scores;
	inputScores(scores);

	vector< vector<double> > users;
	for (int i = 0; i < m; i++) {
		vector<double> user;
		inputScores(user);
		users.push_back(user);
	}

	vector<double> summaries;
	for (int i = 0; i < users.size(); i++) {
		long summary = 0;
		calcScore(scores, users[i], summary);
		summaries.push_back(summary);
	}

	sort(summaries.begin(), summaries.end(), greater<int>());
	for (int i = 0; i < k; i++) {
		cout << summaries[i] << endl;
	}
}
