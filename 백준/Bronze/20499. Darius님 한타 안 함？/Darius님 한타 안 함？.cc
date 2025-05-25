#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;

	int k, d, a;

	int idx = s.find('/');
	k = stoi(s.substr(0,idx));
	int idx2 = s.find('/',idx + 1);
	d = stoi(s.substr( idx+ 1, idx2 - idx));
	idx = idx2 + 1;
	a = stoi(s.substr(idx));

	if (k + a < d || d == 0)
		cout << "hasu";
	else
		cout << "gosu";
}