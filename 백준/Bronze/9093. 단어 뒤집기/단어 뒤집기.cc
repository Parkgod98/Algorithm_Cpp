#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//
//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()

int main()
{
	int n;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; ++i) {
		string s;
		getline(cin, s);
		int index = s.find(' ');
		while (index != -1) {
			string tmp = s.substr(0,index);
			reverse(tmp.begin(), tmp.end());
			cout << tmp << " ";
			s.erase(0,index+1);
			index = s.find(' ');
		}
		reverse(s.begin(), s.end());
		cout << s;
		cout << "\n";
		//RPrint(s);
	}
}
