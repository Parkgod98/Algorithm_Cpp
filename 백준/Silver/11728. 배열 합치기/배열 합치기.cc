#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	list<long long> a, b;
	for (int i = 0; i < N; ++i) {
		long long n;
		cin >> n;
		a.push_back(n);
	}
	for (int i = 0; i < M; ++i) {
		long long n;
		cin >> n;
		b.push_back(n);
	}

	while (!a.empty() && !b.empty()) {
		if (a.front() <= b.front()) {
			cout << a.front() << " ";
			a.pop_front();
		}
		else {
			cout << b.front() << " ";
			b.pop_front();
		}
	}
	while (!a.empty()) {
		cout << a.front() << " ";
		a.pop_front();
	}
	while (!b.empty()) {
		cout << b.front() << " ";
		b.pop_front();
	}

	return 0;
}