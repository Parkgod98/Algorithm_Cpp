//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

int main()
{
	string s;
	cin >> s;

	int len = s.length();
	while (s != "") {
		string t = s.substr(0, 10);
		cout << t << endl;
		s.erase(0, 10);
	}
}
	
