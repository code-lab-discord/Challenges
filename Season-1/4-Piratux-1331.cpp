#include <iostream>
#include <string>
#include <vector>

using namespace std;

void getNumbers(string line, vector<int>& numbers);
long long simpleLCM(long long& lcm, int f, int n);
long long primeLCM(vector<int> numbers, long long lcm);
int getPrime(int n);

int main()
{
	int a = 0, f, n, o;
	long long lcm = 1;
	string line;
	vector<int> numbers;
	cout << "Choose with what numbers you want to find LCM" << endl;
	cout << "1. From 1 to specific number" << endl;
	cout << "2. From specific number to specific number" << endl;
	cout << "3. Several seperate numbers" << endl;
	while (true)
	{
		cin >> o;
		switch (o)
		{
		case 1:
			cout << "Enter specific number" << endl;
			cin >> n;
			f = 1;
			lcm = simpleLCM(lcm, f, n);
			goto loc2;
		case 2:
			cout << "Enter 1st specific number" << endl;
			cin >> f;
			cout << "Enter 2nd specific number" << endl;
			cin >> n;
			for (int i = f; i <= n; i++)
				numbers.push_back(i);
			goto loc1;
		case 3:
			cout << "Enter several numbers seperated by a space" << endl;
			cin.ignore();
			getNumbers(line, numbers);
			goto loc1;
		default:
			cout << "Your option is invalid" << endl;
			break;
		}
	}
	loc1:
	lcm = primeLCM(numbers, lcm);
	loc2:
	cout << lcm << endl;
	return 0;
}
void getNumbers(string line, vector<int>& numbers)
{
	string s = "";
	getline(cin, line);
	for (auto x : line) {
		if (x == ' ')
		{
			numbers.push_back(stoi(s));
			s = "";
		}
		else
			s = s + x;
	}
	numbers.push_back(stoi(s));
}
long long simpleLCM(long long& lcm, int f, int n)
{
	vector<long long> list;
	for (int i = f; i <= n; i++)
	{
		list.push_back(i);
		if (lcm % i == 0)
			continue;
		lcm *= i;
		for (size_t ii = 0; ii < list.size() - 1; ii++)
		{
			if (i % list[ii] == 0)
			{
				lcm /= list[ii];
				list.erase(list.begin() + ii);
			}
		}
	}
	return lcm;
}
long long primeLCM(vector<int> numbers, long long lcm)
{
	bool divided = false;
	int prime = 2;
	int n = 2;
	while (true)
	{
		for (size_t i = 0; i < numbers.size(); i++)
		{
			if (numbers[i] != 1)
				goto loc2;
		}
		return lcm;
		loc2:
		for (size_t i = 0; i < numbers.size(); i++)
		{
			if (numbers[i] % prime == 0)
			{
				numbers[i] /= prime;
				divided = true;
			}
		}
		if (divided == true)
		{
			lcm *= prime;
			divided = false;
		}
		else
		{
			prime = getPrime(n);
			n++;
		}
	}
}
int getPrime(int n)
{
	int p = 1;
	for (int i = 3; ; i += 2)
	{
		for (int j = 3; j < i; j += 2)
		{
			if (i % j == 0)
				goto loc3;
		}
		p++;
		loc3:
		if (p == n)
			return i;
	}
}