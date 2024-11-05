#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <tuple>
#include <algorithm>
using namespace std;

void Reverse(vector<char> &v)
{
	int len = v.size();
	for (int i = 0; i < len / 2; ++i) {
		char tmp = v[i];
		v[i] = v[len - i - 1];
		v[len - i - 1] = tmp;
	}
}

string GetString(vector<char>& v)
{
	string tmp = "";
	for (char c : v)
		tmp += c;
	return tmp;
}


int main(void)
{
	string s, t;
	cin >> s >> t;


	vector<char> v;
	int len = t.length();
	for (int i = 0; i < len; ++i) 
		v.push_back(t[i]);

	int s_size = s.length();
	while (v.size()>=s_size) {
		if (GetString(v) == s) {
			cout << 1;
			return 0;
		}
		if (v[v.size() - 1] == 'A')
			v.pop_back();
		else {
			v.pop_back();
			Reverse(v);
		}
	}
	cout << 0;

	return 0;
}
