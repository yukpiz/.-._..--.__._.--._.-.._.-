#include <iostream>

using namespace std;

struct digit {
	int dig1;
	int dig2;
	int dig3;
	int dig4;
	int dig5;
	int dig6;
	int dig7;
};

string struct2strbin(
	digit dig)
{
	return to_string(dig.dig1) + to_string(dig.dig2)
		+ to_string(dig.dig3) + to_string(dig.dig4)
		+ to_string(dig.dig5) + to_string(dig.dig6)
		+ to_string(dig.dig7);
}

int strbin2i(
	string s)
{
	int ret = 0;
	for (int i = 0, size = s.size(); i < size; i++) {
		ret *= 2;
		ret += ((int)s[i] == 49) ? 1 : 0;
	}
	return ret;
}

/*
 * Number check.
 * +---+----+----+----+----+----+----+----+
 * | n | d1 | d2 | d3 | d4 | d5 | d6 | d7 |
 * +---+----+----+----+----+----+----+----+
 * | 0 |  1 |  1 |  1 |  1 |  1 |  1 |  0 |
 * | 1 |  0 |  1 |  1 |  0 |  0 |  0 |  0 |
 * | 2 |  1 |  1 |  0 |  1 |  1 |  0 |  0 |
 * | 3 |  1 |  1 |  1 |  1 |  0 |  0 |  1 |
 * | 4 |  0 |  1 |  1 |  0 |  0 |  1 |  1 |
 * | 5 |  1 |  0 |  1 |  1 |  0 |  1 |  1 |
 * | 6 |  1 |  0 |  1 |  1 |  1 |  1 |  1 |
 * | 7 |  1 |  1 |  1 |  0 |  0 |  1 |  0 |
 * | 8 |  1 |  1 |  1 |  1 |  1 |  1 |  1 |
 * | 9 |  1 |  1 |  1 |  1 |  0 |  1 |  1 |
 */
bool isNumber(
	digit dig)
{
	string strbin = struct2strbin(dig);
	int decimal = strbin2i(strbin);
	return decimal == 126 or decimal == 48 or
		decimal == 108 or decimal == 121 or
		decimal == 51 or decimal == 91 or
		decimal == 95 or decimal == 114 or
		decimal == 127 or decimal == 123 ? true : false;
}

void changeInt(
	int &one,
	int &two)
{
	int tmp = one;
	one = two;
	two = tmp;
}

digit toRotate(
	digit dig)
{
	changeInt(dig.dig1, dig.dig4);
	changeInt(dig.dig2, dig.dig5);
	changeInt(dig.dig3, dig.dig6);
	return dig;
}

digit toSymmetry(
	digit dig)
{
	changeInt(dig.dig2, dig.dig6);
	changeInt(dig.dig3, dig.dig5);
	return dig;
}

int main(
	int arg,
	char **args)
{
	struct digit one;
	cin >> one.dig1 >> one.dig2 >> one.dig3 >> one.dig4
		>> one.dig5 >> one.dig6 >> one.dig7;

	struct digit two;
	cin >> two.dig1 >> two.dig2 >> two.dig3 >> two.dig4
		>> two.dig5 >> two.dig6 >> two.dig7;

	string ret = isNumber(one)
		and isNumber(two) ? "Yes" : "No";
	cout << ret << endl;

	ret = isNumber(toSymmetry(one))
		and isNumber(toSymmetry(two)) ? "Yes" : "No";
	cout << ret << endl;

	ret = isNumber(toRotate(one))
		and isNumber(toRotate(two)) ? "Yes" : "No";
	cout << ret << endl;
}
