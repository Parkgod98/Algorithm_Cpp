//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

vector<string> split(string input, string delimeter) {
	vector<string> res;
	long long pos = 0;
	string token = "";

	while ((pos = input.find(delimeter)) != string::npos) {
		token = input.substr(0, pos);
		res.push_back(token);
		input.erase(0, pos + delimeter.length());
	}
	res.push_back(input);

	return res;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		int sum = 0;
		vector<string> res = split(s, "X");
		for (string s : res) {
			for (int i = 1; i <= s.size(); ++i)
				sum += i;
		}
		cout << sum << "\n";
	}
}