#include <iostream>

using namespace std;

int main()
{
	int n, x;

	cin >> n >> x;

	int count = 0;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		if (k < x)
			cout << k << " ";
	}
}