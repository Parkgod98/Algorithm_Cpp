//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
using namespace std;


//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()

bool IsPossible(string s)
{
	int count[26] = { 0 };
	int len = s.length();

	for (char c : s) {
		count[c-'A']++;
	}
	if (len % 2 == 0) {
		for (int i : count)
			if (i % 2 == 1)
				return false;
	}
	else {
		for (int i = 0; i < 26; ++i) {
			if (count[i] % 2 == 1) {
				count[i]--;
				break;
			}
		}
		for (int i : count)
			if (i % 2 == 1)
				return false;
	}
	return true;
}

void PrintV(vector<char> c) {
	for (char i : c) {
		cout << i;
	}
}

int main()
{
	string s;
	cin >> s;

	if (IsPossible(s)) {
		
		int count[26] = { 0 };
		int len = s.length();

		for (char c : s)
			count[c - 'A']++;

		vector<char> v(1);
		if (len % 2 == 1) {
			for (int i = 0; i < 26; ++i)
				if (count[i]%2 == 1) {
					count[i]--;
					v[0] = (char)(i+'A');
					break;
				}
			
		}
	
		for (int i = 0; i < 26; ++i) {
			while (count[i] != 0) {
				if (v.size() % 2 == 1) {
					v.insert(v.begin() + v.size() / 2, i + 'A');
				}
				else {
					v.insert(v.begin() + v.size() / 2 + 1, i + 'A');
				}
				count[i]--;
			}
		}
		if(len%2 == 0)
			v.erase(v.begin() + (v.size() / 2));
		PrintV(v);
	}
	else
		cout << "I'm Sorry Hansoo" << "\n";
}