#include<iostream>
using namespace std;
#define SIZE 1000002

int arr[SIZE];
int main(int argc, char** argv)
{
	int T;
	cin >> T;
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int tc = 1; tc <= T; ++tc) {
		int N;
		cin >> N;

		for (int i = 0; i < N; ++i) {
			cin >> arr[i];
		}

		int mx = arr[N - 1];
		long long sum = 0;
		for (int i = N - 1; i >= 0; --i) {
			if (mx < arr[i])
				mx = arr[i];
			sum += (mx - arr[i]);

		}
		cout << "#" << tc << " " << sum << "\n";
	}
}