#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
#include <set>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

int N;
int d, w;
vector<pair<int, int>> v;

int day[1001];
bool cmp(pair<int, int> &a, pair<int, int> &b) {
	if (a.second != b.second)
		return a.second > b.second;
}
int main(){
	
	cin >> N;
	v = vector<pair<int, int>>(N);
	for (int i = 0; i < N; ++i) {
		cin >> d >> w;
		v[i] = { d,w };
	}

	sort(v.begin(), v.end(),cmp);

	for (int i = 0; i < N; ++i) {

		for (int j = v[i].first; j > 0; --j) {

			if (day[j] == 0) {
				day[j] = v[i].second;
				break;
			}
		}
	}

	int sum = 0;
	for (int i = 1; i <= 1000; ++i)
		sum += day[i];

	cout << sum << "\n";
}
