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
	int arr[26] = { 0 };
	string s;
	
	cin >> s;
	int len = s.length();
	for (int i = 0; i < len; ++i) {
		arr[s[i] - 'a'] += 1;
	}
	for (int i : arr)
		cout << i << " ";

}
