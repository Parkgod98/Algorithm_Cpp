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
	string a, b;

	cin >> a >> b;
	reverse(a.begin(),a.end());
	reverse(b.begin(), b.end());
	if (stoi(a) > stoi(b))
		cout << a;
	else
		cout << b;
}