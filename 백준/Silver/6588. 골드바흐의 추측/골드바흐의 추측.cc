#include <iostream>
#include <vector>
#include <queue>
using namespace std;
short v[1000001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fill(v, v + 1000001, 1);
	v[0] = v[1] = 0;
	for (int i = 2; i * i <= 1000000; ++i) {
		for (int j = i*i; j <= 1000000; j+=i){
			if (v[j])
				v[j] = 0;
		}
	}

	while(1){
		int n;
		cin >> n;
		if (n == 0)
			break;

		bool Find = false;
		for (int i = 2; i <= n/2; ++i) {
			if (v[i] && v[n - i]) {
				cout << n << " = " << i << " + " << n - i << "\n";
				Find = true;
				break;
			}
		}
		if (!Find) {
			cout << "Goldbach's conjecture is wrong." << "\n";
		}
	}
}