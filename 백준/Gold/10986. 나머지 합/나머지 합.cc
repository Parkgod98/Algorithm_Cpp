#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N, M;
typedef long long ll;
vector<int> v;
vector<int> p_sum;

int main()
{
	cin >> N >> M;
	v = vector<int>(N + 1);
	p_sum = vector<int>(N + 1);

	for (int i = 1; i <= N; ++i) {
		cin >> v[i];
	}

	for (int i = 1; i <= N; ++i) {
		p_sum[i] = p_sum[i - 1] + v[i];
		p_sum[i] %= M;
	}

	vector<int> num(M);

	for (int i = 1; i <= N; ++i) {
		num[p_sum[i]]++;
	}

	long long cnt = 0;

	for (int i = 0; i < M; ++i) {
		cnt += ((long long)num[i] * (num[i] - 1)) / 2;
	}
	cnt += num[0];

	cout << cnt << "\n";
}