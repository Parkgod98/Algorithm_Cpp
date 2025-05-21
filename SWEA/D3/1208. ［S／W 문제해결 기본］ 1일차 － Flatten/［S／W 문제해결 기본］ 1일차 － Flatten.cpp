#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	for(int tc = 1; tc <= 10; ++tc) {
		int n;
		cin >> n;
		
		vector<int> v(100, 0);
		for(int i = 0; i < 100; ++i)
			cin >> v[i];

		while(1) {
			sort(v.begin(), v.end(),greater<int>());
			if(v[0] - v[99] <= 1 || n == 0)
				break;
			v[0]--;
			v[99]++;
			n--;
		}
		cout << "#" << tc << " " << v[0] - v[99] << "\n";
	}
}