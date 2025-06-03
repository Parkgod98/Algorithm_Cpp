#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <unordered_map>
#include <queue>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> A(N), B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());

	int S = 0;
	for (int i = 0; i < N; ++i)
		S += A[i] * B[i];

	cout << S << "\n";
}
