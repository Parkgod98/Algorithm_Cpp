#include <iostream>
#include <vector>
using namespace std;

int func3(int N)
{
	for (int i = 1; i * i <= N; ++i) {
		if (i * i == N)
			return 1;
	}
	return 0;
}

int main(void)
{
	int n, x;
	cin >> n >> x;

	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		if (k < x)
			cout << k << " ";
	}

}