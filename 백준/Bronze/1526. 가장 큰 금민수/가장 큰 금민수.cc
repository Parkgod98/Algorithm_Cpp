#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
vector<int> v;

void Make(int n, int depth) {
	v.push_back(n);
	if (depth == 6)
		return;
	Make(n * 10 + 4, depth + 1);
	Make(n * 10 + 7, depth + 1);

}

int main() {
	int N;
	cin >> N;
	Make(4, 1);
	Make(7, 1);

	int mx = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] <= N && mx < v[i]) {
			mx = v[i];
		}
	}
	cout << mx << "\n";
}