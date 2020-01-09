#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s, st = "";
	getline(cin, s);
	for (int i = s.length()-1; i >= 0; i--)
		st = st + s[i];
	cout << st;
	return 0;
}