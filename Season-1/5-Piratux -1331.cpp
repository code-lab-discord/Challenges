#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctype.h>

using namespace std;

struct list {
	string orgName;
	vector<string> chName;
	vector<int> chNum;
};

void Read(vector<list>& l)
{
	int counter = 10;
	bool readingVar;
	string line, varName = "";
	ifstream fin("input.txt");
	while (true)
	{
		counter++;
		readingVar = false;
		getline(fin, line);
		for (auto x : line)
		{
			if (x == ']')
				return;
			if (x == '{')
			{
				l.push_back(list());
				counter = 0;
				break;
			}
			if (isalpha(x) || isdigit(x))
			{
				if(readingVar)
					varName += x;
			}
			else
			{
				if(x == ':')
					readingVar = true;
			}
		}
		switch (counter)
		{
		case 1:
			l[l.size() - 1].orgName = varName;
			break;
		case 2:
			l[l.size() - 1].chName.push_back(varName);
			break;
		case 3:
			l[l.size() - 1].chNum.push_back(stoi(varName));
			break;
		default:
			break;
		}
		varName = "";
	}
}
void createList(vector<list>& l)
{
	for (int i = 0; i < l.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (l[j].orgName == l[i].orgName)
			{
				l[j].chName.push_back(l[i].chName[0]);
				l[j].chNum.push_back(l[i].chNum[0]);
				l.erase(l.begin() + i);
			}
		}
	}
}
void Output(vector<list>& l)
{
	ofstream fout("output.txt");
	char c = '"';
	fout << "[" << endl;
	for (int i = 0; i < l.size(); i++)
	{
		fout << "{ " << c << l[i].orgName << c << " : [";
		for (int j = 0; j < l[i].chName.size(); j++)
		{
			fout << "{";
			fout << c << l[i].chName[j] << c << " : ";
			fout << c << l[i].chNum[j] << c;
			fout << "}";
			if (j + 1 != l[i].chName.size())
				fout << ", ";
		}
		fout << "]}";
		if (i + 1 != l.size())
			fout << ",";
		fout << endl;
	}
	fout << "]";
}
int main()
{
	vector<list> l;
	Read(l);
	createList(l);
	Output(l);
	return 0;
}