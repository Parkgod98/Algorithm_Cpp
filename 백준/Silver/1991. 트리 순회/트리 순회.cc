#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int N;
vector<vector<char>> v;

void Pre(char cur) {
	if (cur == '.')
		return;
	cout << cur;

	Pre(v[cur-'A'+1][0]);
	Pre(v[cur-'A'+1][1]);
}

void Mid(char cur) {
	if (cur == '.')
		return;

	Mid(v[cur - 'A' + 1][0]);
	cout << cur;
	Mid(v[cur - 'A' + 1][1]);
}

void Post(char cur) {
	if (cur == '.')
		return;

	Post(v[cur - 'A' + 1][0]);
	Post(v[cur - 'A' + 1][1]);
	cout << cur;
}


int main(void) {
	cin >> N;
	v = vector<vector<char>>(N + 1, vector<char>(2));
	for (int i = 1; i <= N; ++i) {
		char a, b, c;
		cin >> a >> b >> c;
		v[a - 'A' + 1][0] = b;
		v[a - 'A' + 1][1] = c;
	}

	Pre('A');
	cout << "\n";
	Mid('A');
	cout << "\n";
	Post('A');
}