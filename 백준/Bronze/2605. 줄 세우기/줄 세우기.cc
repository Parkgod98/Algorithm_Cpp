#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;


int main() {
	int n;
	cin >> n;
	list<int> v;

	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;

		auto it = v.begin();
		advance(it, i - k);
		v.insert(it, i+1);
	}

	for (int &i : v)
		cout << i << " ";
}