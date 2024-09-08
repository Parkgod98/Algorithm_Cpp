//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

int main()
{
	int a;
	string s;
	cin >> a >> s;

	cout << a * (s[2] - '0') << "\n" << a * (s[1] - '0') << "\n" << a * (s[0] - '0') << "\n" << a * stoi(s);

}
