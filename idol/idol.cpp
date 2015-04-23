#include <iostream>
#include <vector>

using namespace std;

vector<string> split(
	string &str,
	char delim)
{
	vector<string> res;
	size_t cur = 0, found;
	while ((found = str.find_first_of(delim, cur)) != string::npos) {
		res.push_back(string(str, cur, found - cur));
		cur = found + 1;
	}
	res.push_back(string(str, cur, str.size() - cur));
	return res;
}

vector<int> vtoi(
	vector<string> &v)
{
	vector<int> iv;
	for (int i = 0; i < v.size(); i++) {
		iv.push_back(atoi(v[i].c_str()));
	}
	return iv;
}

vector<int> str2vi(
	string &str)
{
	vector<string> v = split(str, ' ');
	return vtoi(v);
}

int interests(
	vector<int> &moneys)
{
	int summury = 0;
	for (int i = 0; i < moneys.size(); i++) {
		summury += moneys[i];
	}
	return summury < 0 ? 0 : summury;
}

vector<int> inputLive()
{
	string line;
	getline(cin, line);
	return str2vi(line);
}

int main(
	int arg,
	char **args)
{
	int n, m;
	cin >> n >> m;
	cin.ignore();

	vector< vector<int> > lives;
	for (int i = 0; i < m; i++) {
		lives.push_back(inputLive());
	}

	int summary = 0;
	for (int i = 0; i < lives.size(); i++) {
		summary += interests(lives[i]);
	}
	cout << summary << endl;
}
