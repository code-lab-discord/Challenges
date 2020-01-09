#include <iostream>
#include <string>

using namespace std;

int main()
{
	int a = 0;
	string s, st[1000];
	cout << "Enter the sentence" << endl;
	getline(cin, s);
	for (auto x : s) {
		if (x == ' ')
			a++;
		else
			st[a] = st[a] + x;
	}
	for (int i = 0; i < a; i++)
	{
		string temp = st[i+1];
		while (i >= 0 && temp.length() < st[i].length())
		{
			st[i + 1] = st[i];
			i--;
		}
		st[i + 1] = temp;
	}
	cout << endl << "Here is your sorted sentence:" << endl;
	for (int i = a; i > -1; i--)
		cout << st[i] << " ";
	cout << endl;
	return 0;
}