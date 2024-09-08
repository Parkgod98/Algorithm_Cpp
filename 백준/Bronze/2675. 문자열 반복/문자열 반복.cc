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
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int a;
		string s;
		cin >> a >> s;
		
		int len = s.length();
		for (int i = 0; i < len; ++i) {
			for (int j = 0; j < a; ++j)
				cout << s[i];
		}
		cout << "\n";
	}
}
