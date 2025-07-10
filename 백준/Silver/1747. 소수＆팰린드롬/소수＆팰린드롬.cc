#include <iostream>
#include <vector>
#include <queue>
using namespace std;
short v[10000001];

bool IsPalindrome(int n) {
	int origin = n;
	int rev = 0;

	while (n != 0) {
		rev = rev * 10 + n % 10;
		n /= 10;
	}
	if (rev == origin)
		return true;
	return false;
}
int main()
{
	fill(v, v + 10000001, 1);
	v[0] = v[1] = 0;
	for (int i = 2; i * i <= 10000000; ++i) {
		for (int j = i*i; j <= 10000000; j+=i){
			if (v[j])
				v[j] = 0;
		}
	}

	int N;
	cin >> N;

	int i = N;
	while (1) {
		if (v[i]) {
			if (IsPalindrome(i)) {
				cout << i << "\n";
				return 0;
			}
		}
		i++;
	}
}