#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int N, T, P;
vector<int> v(6);
int main() {
	cin >> N;

	for (int i = 0; i < 6; ++i)
		cin >> v[i];

	cin >> T >> P; 

	int res1 = 0;
	for (int i = 0; i < 6; ++i) {
		int mok = ceil((double)v[i] / T);
		res1 += mok;
	}

	cout << res1 << "\n";
	cout << N / P << " " << N % P << "\n";

}