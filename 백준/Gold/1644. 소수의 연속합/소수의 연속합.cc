#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N;
vector<bool> prime_list;
vector<int> prime_num;
int main() {
	cin >> N;
	if (N == 1) {
		cout << 0 << "\n";
		return 0;
	}

	prime_list = vector<bool>(N + 1,true);
	prime_list[0] = prime_list[1] = false;
	
	for (int i = 2; i * i <= N; ++i) {
		if (prime_list[i]) {
			for (int j = i * i; j <= N; j += i)
				prime_list[j] = false;
		}
	}
	for (int i = 2; i <= N; ++i)
		if(prime_list[i])
			prime_num.push_back(i);

	int sz = prime_num.size();

	int i, j;
	i = j = 0;
	int sum = prime_num[0];
	int cnt = 0;
	while (i < sz && j < sz) {
		if (sum < N) {
			j++;
			if (j < sz) {
				sum += prime_num[j];
			}
		}
		else if (sum == N) {
			++cnt;
			sum -= prime_num[i];
			i++;
		}
		else {
			sum -= prime_num[i];
			i++;
		}
	}

	cout << cnt << "\n";


}