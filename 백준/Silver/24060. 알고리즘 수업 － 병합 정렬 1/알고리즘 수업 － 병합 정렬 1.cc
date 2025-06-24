#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int N, K, res,cnt;

void merge(vector<int> &A, int start, int mid, int end) {
	int i = start;
	int j = mid + 1;
	int t = 0;

	vector<int> tmp(end - start + 1);
	while (i <= mid && j <= end) {
		if (A[i] <= A[j]) {
			tmp[t] = A[i];
			i++;
			t++;
		}
		else {
			tmp[t] = A[j];
			j++;
			t++;
		}
	}

	while (i <= mid) {
		tmp[t] = A[i];
		t++;
		i++;
	}
	while (j <= end) {
		tmp[t] = A[j];
		t++;
		j++;
	}

	for (int i = start; i <= end; ++i) {
		cnt++;
		A[i] = tmp[i - start];
		if (cnt == K)
			res = A[i];
	}
}

void merge_sort(vector<int> &A, int start, int end) {

	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(A, start, mid);
		merge_sort(A, mid + 1, end);
		merge(A, start, mid, end);
	}
}

int main() {
	cin >> N >> K;

	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}

	merge_sort(A, 0, N - 1);

	if (res != 0)
		cout << res << "\n";
	else
		cout << -1 << "\n";
}  