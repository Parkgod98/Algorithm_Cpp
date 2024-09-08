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
	vector<string> ret;
	string token = "";
	long long pos = 0;
	while ((pos = input.find(delimeter)) != string::npos) {
		token = input.substr(0, pos);
		ret.push_back(token);
		input.erase(0, pos + delimeter.length());
	}
	ret.push_back(input);

	return ret;
}

int main()
{
	string s;
	getline(cin, s);

	vector<string> res = split(s, " ");
	
	int sum = 0;
	for (string s : res) {
		if (s != "")
			sum += 1;
	}
	cout << sum;
}
	
