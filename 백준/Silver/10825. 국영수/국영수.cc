#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

struct Student {
	string name;
	int kr, en, math;
};

bool compare(Student &a, Student &b) {
	if (a.kr != b.kr) {
		return a.kr > b.kr;
	}
	if (a.en != b.en) {
		return a.en < b.en;
	}
	if (a.math != b.math)
		return a.math > b.math;
	return a.name < b.name;
}

int main() {
	int N;
	cin >> N;

	vector<Student> v(N);
	for (int i = 0; i < N; ++i) {
		string s;
		int k, e, m;
		cin >> s >> k >> e >> m;

		v[i] = { s,k,e,m };
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < N; ++i)
		cout << v[i].name << "\n";
}
