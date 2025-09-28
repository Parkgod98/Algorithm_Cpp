#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <stack>
#include <cmath>
using namespace std;
int N;
int K;

void Hanoi(int n, int start, int mid, int end) {
	if (n == 1) {
		cout << start << " " << end << "\n";
		return;
	}
	Hanoi(n - 1, start, end, mid);
	cout << start << " " << end << "\n";
	Hanoi(n - 1, mid, start, end);
}

int main() {
	cin >> N;

	string cnt = to_string(pow(2, N));
	int idx = cnt.find('.');
	cnt = cnt.substr(0, idx);

	cnt[cnt.length() - 1] -= 1;
	cout << cnt << "\n";
	if(N <= 20)
		Hanoi(N, 1, 2, 3);
}