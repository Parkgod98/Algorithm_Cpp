#include <bits/stdc++.h>
using namespace std;

int arr[2000001];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;

	vector<int> v(n);
	for(int i = 0; i < n; ++i)
		cin >> v[i];
	int x;
	cin >> x;

	int cnt = 0;
	for(int i = 0; i < n; ++i) {
		if(x - v[i] >= 1 && arr[x - v[i]] == 1) {
			++cnt;
			continue;
		}
		arr[v[i]] = 1;
		
	}
	cout << cnt;
}