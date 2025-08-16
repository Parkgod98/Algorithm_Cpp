#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> M;
		int mask = (1 << N) - 1;
		if ((M&mask) == mask) {
			cout << "#" << tc << " " << "ON" << "\n";
		}
		else
			cout << "#" << tc << " " << "OFF" << "\n";
	}
}