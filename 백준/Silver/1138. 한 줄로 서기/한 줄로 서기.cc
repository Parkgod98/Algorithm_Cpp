#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 100
int main()
{
	int N;
	cin >> N;

	vector<int> v(N + 1,INF);

	for (int i = 1; i <= N; ++i) {
		int n;
		cin >> n;

		for (int start = n+1; start <= N; ++start) {
			if (v[start] != INF)
				continue;
			int cnt = 0;
			for (int j = 1; j < start; ++j){
				if (v[j] > i) {
					++cnt;
				}
			}
			if (cnt == n) {
				v[start] = i;
				break;
			}
		}
	}

	for (int i = 1; i <= N; ++i)
		cout << v[i] << " ";
	cout << "\n";
}