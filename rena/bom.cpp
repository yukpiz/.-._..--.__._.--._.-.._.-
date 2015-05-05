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
	string &line)
{
	vector<string> v = split(line, ' ');
	return vtoi(v);
}

void exBomb(
	vector<int> &line)
{
	for (int i = 0; i < line.size(); i++) {
		line[i] = line[i] == 2 ? 0 : line[i];
	}
}

void downLine(
	vector<int> &top,
	vector<int> &bottom)
{
}

int main()
{
	int x, y;
	cin >> x >> y;
	cin.ignore();

	vector< vector<int> > lines;
	string line;
	for (int i = 0; i < y; i++) {
		getline(cin, line);
		lines.push_back(str2vi(line));
	}

	//上のラインから下のラインへ向けて
	//

	return 0;
}
