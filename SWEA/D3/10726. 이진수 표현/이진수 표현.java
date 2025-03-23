#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case) {
		int n, m;
		cin >> n >> m;

		int mask = (1 << n) - 1;
		m = m & mask;
		if(m == mask) {
			cout << "#" << test_case << " " << "ON" << "\n";
		}
		else {
			cout << "#" << test_case << " " << "OFF" << "\n";
		}
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
