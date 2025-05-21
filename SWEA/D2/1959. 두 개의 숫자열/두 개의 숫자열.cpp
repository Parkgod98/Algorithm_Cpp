#include <iostream>
#include <string>
#include <vector>
using namespace std;
int N, M;

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> M;

		vector<int> ai(N), bi(M);
		for (int i = 0; i < N; ++i)
			cin >> ai[i];
		for (int i = 0; i < M; ++i)
			cin >> bi[i];
		if (N > M) {
			swap(ai, bi);
			swap(N, M);
		}

		int mx = 0;
		for (int i = 0; i < M - N + 1; ++i) {
			int sum = 0;
			for (int j = i; j < i + N; ++j) {
				sum += ai[j-i] * bi[j];
			}
			if (i == 0)
				mx = sum;
			else {
				if (mx < sum)
					mx = sum;
			}
		}
		cout << "#" << tc << " " << mx << "\n";
	}
}