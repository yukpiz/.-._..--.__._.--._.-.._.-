#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector< vector<int> >::iterator iterator;
	vector<int> zero{0, 0, 0, 0};

	vector< vector<int> > trainings;
	for (int i = 0; i < n; i++) {
		int t1, t2, t3, t4;
		cin >> t1 >> t2 >> t3 >> t4;
		vector<int> training{t1, t2, t3, t4};
		trainings.push_back(training);
	}
	iterator = trainings.begin();
	trainings.insert(iterator, 1, zero);

	vector< vector<int> > skills;
	for (int i = 0; i < m; i++) {
		int s1, s2, s3, s4;
		cin >> s1 >> s2 >> s3 >> s4;
		vector<int> skill{s1, s2, s3, s4};
		skills.push_back(skill);
	}
	iterator = skills.begin();
	skills.insert(iterator, 1, zero);
	return 0;
}


