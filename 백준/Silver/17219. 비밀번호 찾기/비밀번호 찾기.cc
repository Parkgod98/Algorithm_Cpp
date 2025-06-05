#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	unordered_map<string, string> mp;
	for (int i = 0; i < N; ++i) {
		string site, pw;
		cin >> site >> pw;

		mp[site] = pw;
	}

	for (int i = 0; i < M; ++i) {
		string site;
		cin >> site;

		cout << mp[site] << "\n";
	}
}
