#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
#include <set>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

int N;
int main(){

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N;

		int cur_velocity = 0;
		int dist = 0;
		for (int i = 0; i < N; ++i) {
			int com,v;
			cin >> com;

			if (com == 1) {
				cin >> v;
				cur_velocity += v;
			}
			else if(com == 2) {
				cin >> v;
				cur_velocity -= v;
				if (cur_velocity < 0)
					cur_velocity = 0;
			}

			dist += (cur_velocity);
		}

		cout << "#" << tc << " " << dist << "\n";
	}

}
