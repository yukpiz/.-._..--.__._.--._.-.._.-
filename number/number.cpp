/*
 * [Compile]
 *   g++ -std=c++11 number.cpp -o number
 */

#include <iostream>
#include <vector>

using namespace std;

int main(
		int arg,
		char **args)
{
	int num;
	cin >> num;

	int count;
	cin >> count;

	vector<int> rooms;
	for (int i = 0; i < count; i++) {
		int room;
		cin >> room;
		rooms.push_back(room);
	}

	bool findflg = false;
	for (int i = 0; i < rooms.size(); i++) {
		string room = to_string(rooms[i]);
		if (room.find(to_string(num), 0) == string::npos) {
			cout << room << endl;
			findflg = true;
		}
	}
	if (!findflg) {
		cout << "none" << endl;
	}
}
