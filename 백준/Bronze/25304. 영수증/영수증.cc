//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

int main()
{
	
	long long X;
	int N;

	// X : 총 금액, N : 구매한 물건 종류
	cin >> X >> N;
	for (int i = 0; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		X -= a * b;
	}
	if (X == 0)
		cout << "Yes" << "\n";
	else
		cout << "No" << "\n";
}