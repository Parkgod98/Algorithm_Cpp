#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
using namespace std;
int N;

int main() {
	int N;
	cin >> N;

	vector<int> v;
	for (int i = 1; i <= N; ++i)
		v.push_back(i);

	sort(v.begin(), v.end());

	do {
		for (int &i : v)
			cout << i << " ";
		cout << "\n";
	} while (next_permutation(v.begin(), v.end()));
}  