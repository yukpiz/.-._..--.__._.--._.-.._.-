#include<iostream>

int main()
{
	int n;
	cin >> n;
	set<int> s;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		s.insert(y - x);
	}
}
