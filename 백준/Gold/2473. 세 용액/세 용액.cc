#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstdlib>
using namespace std;
int N;
typedef long long ll;

vector<ll> v;
int main()
{
	cin >> N;
	v = vector<ll>(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());
	ll INF = 21000000000;

	ll min_sum = INF;

	int ans[3] = { 0,0,0 };
	for (int k = 0; k < N - 2; ++k) {
		int i = k + 1;
		int j = N - 1;

		while (i < j) {
			ll sum = v[k] + v[i] + v[j];

			if (llabs(sum) < min_sum) {
				ans[0] = v[k];
				ans[1] = v[i];
				ans[2] = v[j];
				min_sum = llabs(sum);
			}
			if (sum > 0) {
				--j;
			}
			else if (sum < 0) {
				++i;
			}
			else {
				break;
			}
		}
	}


	for (int i = 0; i < 3; ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";
}