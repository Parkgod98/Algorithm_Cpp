#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<char> v;
vector<int> visited(10);
string mx = "0";
string mn = "9999999999";
void DFS(int depth, string &s) {
	if (depth == N + 1) {
		if (stoll(mx) < stoll(s)) {
			mx = s;
		}
		if (stoll(mn) > stoll(s)) {
			mn = s;
		}
		return;
	}
	for (int i = 0; i <= 9; ++i) {
		if (s.size() == 0 && !visited[i]) {
			s.push_back(i + '0');
			visited[i] = 1;
			DFS(depth + 1, s);
			s.pop_back();
			visited[i] = 0;
		}
		else {
			char op = v[depth - 1];
			if (op == '<') {
				if (s[s.size() - 1] < (i + '0') && !visited[i]) {
					s.push_back(i + '0');
					visited[i] = 1;
					DFS(depth + 1, s);
					s.pop_back();
					visited[i] = 0;
				}
			}
			else if (op == '>') {
				if (s[s.size() - 1] > (i + '0') && !visited[i]) {
					s.push_back(i + '0');
					visited[i] = 1;
					DFS(depth + 1, s);
					s.pop_back();
					visited[i] = 0;
				}
			}
		}
	}
}

int main(void) {
	cin >> N;
	v = vector<char>(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];

	string s = "";
	DFS(0, s);
	cout << mx << "\n" << mn << "\n";
}
