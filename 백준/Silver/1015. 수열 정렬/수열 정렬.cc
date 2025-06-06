#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<pair<int,int>> A(N);
	vector<int> v(N);
	for (int i = 0; i < N; ++i) {
		int n;
		cin >> n;
		A[i] = { n,i };
	}

	stable_sort(A.begin(), A.end());
	vector<int> res(N);
	for (int i = 0; i < N; ++i) {
		res[A[i].second] = i;
	}

	for (int &i : res)
		cout << i << " ";
}