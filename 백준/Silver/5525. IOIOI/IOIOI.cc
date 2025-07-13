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

	string mask(2*N+1,'a');
	for (int i = 0; i < 2*N + 1; ++i) {
		if (i % 2 == 0)
			mask[i] = 'I';
		else
			mask[i] = 'O';
	}

	int idx = S.find(mask);
	int cnt = 0;
	if (idx != -1) {
		++cnt;
		idx++;
	}
	while (idx != string::npos) {
		idx = S.find(mask, idx);
		if (idx != -1) {
			++cnt;
			idx = idx + 1;

		}
	}

	cout << cnt << "\n";
}
