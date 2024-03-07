#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
int count(string g,char c) {
	int counter = 0;
	for (int i = 0;i < g.length();i++)
	{
		if (g[i] == c) {
			counter++;
		}
	}
	return counter;
}

int main()
{
	int j = 0;
	string s;
	cin >> s;
	string k = s.substr(0, s.length() / 2);
	string b = s.substr(s.length() / 2, s.length() / 2);
	if (s.length()%2==0)
	{
		for (int i = 97;i <= 122;i++) {
			if (count(k, (char(i)) == count(b, (char(i))))) {
				continue;
			}
			else
			{ j=1;}
		}
		if (j == 0) {
			cout<<"YES";
		}
		else
		{cout<<"NO"; }
	}
	else
	{cout<<"NO"<<endl; }
}