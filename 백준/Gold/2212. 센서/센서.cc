#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
int N,K;

int main(void) {
	cin >> N;
	cin >> K;

	vector<int> v(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());
	
	vector<int> ans;
	for (int i = 0; i < N - 1; ++i)
		ans.push_back(v[i + 1] - v[i]);
	sort(ans.begin(), ans.end());

	int sum = 0;
	for (int i = 0; ans.size() != 0 && i < ans.size() -(K-1); ++i)
		sum += ans[i];
	cout << sum << "\n";
}
