#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
using namespace std;
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//
//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()

int res = -5000000;


int Cal(int a, int b, char op)
{
	switch (op) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
	}
}

void DFS(int idx, int cur, vector<int> &num, vector<char> &oper)
{
	if (idx == num.size() - 1) {
		res = max(cur, res);
		return;
	}
	DFS(idx + 1, Cal(cur, num[idx + 1], oper[idx]), num, oper);
	if (idx + 2 <= num.size() - 1) {
		int tmp = Cal(num[idx + 1], num[idx + 2], oper[idx + 1]);
		DFS(idx + 2, Cal(cur, tmp, oper[idx]), num, oper);
	}
	return;

}

int main()
{
	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<int> num;
	vector<char> oper; 
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0)
			num.push_back(s[i] - '0');
		else
			oper.push_back(s[i]);
	}
	DFS(0,num[0], num, oper);
	cout << res;
}
