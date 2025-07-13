#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int N, M;
	cin >> N >> M;
	string S;
	cin >> S;

	int cnt = 0;
	for (int i = 0; i < M-2; ++i) {
		if (S[i] == 'O')
			continue;

		int Pn = 0;
		while (S[i + 1] == 'O' && S[i + 2] == 'I') {
			Pn++;
			if (Pn == N) {
				++cnt;
				Pn--;
			}
			i += 2;
		}
	}

	cout << cnt << "\n";
}
