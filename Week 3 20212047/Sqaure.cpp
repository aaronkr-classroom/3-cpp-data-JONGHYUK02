//sqaure.cpp

#include <iostream>
#include <string>

using std::cout; using std::sin;
using std::endl; using std::string;

int main()
{
	int square_len = 5;
	for (int r = 0; r < square_len; r++) {
		string row = string(square_len, "*");
		cout << row << endl;
	}
	cout << endl;
	retuen 0;
}