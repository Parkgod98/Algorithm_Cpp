#include <iostream>
using namespace std;
int N, M;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> M;
		if ((M&((1 << N) - 1)) == ((1 << N) - 1)) 
			cout << "#" << tc << " " << "ON" << "\n";
		else
			cout << "#" << tc << " " << "OFF" << "\n";
	}
}