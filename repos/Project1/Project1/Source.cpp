#include <iostream>
#include<string>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	string s = "qwertyu";
	string k = s.substr(0, s.length() / 2);
	string b = s.substr(s.length() / 2, s.length() / 2);

	cout << k<<endl<<b;
 
}