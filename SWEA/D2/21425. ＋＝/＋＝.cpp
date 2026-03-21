#include<iostream>
using namespace std;

int A, B, N;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> A >> B >> N;

		long long cnt = 0;

		while (1) {
			if (A > N || B > N) {
				break;
			}
			if (A < B) {
				A += B;
			}
			else
				B += A;
			++cnt;
		}

		cout << cnt << "\n";
	}

}