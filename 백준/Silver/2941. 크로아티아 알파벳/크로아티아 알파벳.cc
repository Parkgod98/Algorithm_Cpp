#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
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
	string arr[8] = { "c=","c-","dz=","d-","lj","nj","s=","z=" };

	string s;
	cin >> s;

	for (int i = 0; i < 8; ++i) {
		int idx = s.find(arr[i]);
		while (idx != -1) {
			s.replace(idx, arr[i].length(), "#");
			idx = s.find(arr[i]);
		}
	}
	cout << s.length();

}
