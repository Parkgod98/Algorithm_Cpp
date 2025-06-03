#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <deque>
#include <set>
using namespace std;

int main() {
	int N;
	cin >> N;

	int i, j;
	i = 1;
	j = 1;
	int sum = 1;
	int cnt = 0;
	while (j <=N && i <= j ) {
		if (sum == N) {
			++cnt;
			sum -= i;
			i++;
		}
		else if (sum > N) {
			sum -= i;
			++i;
		}
		else {
			j++;
			sum += j;
		}
	}

	cout << cnt << "\n";
}