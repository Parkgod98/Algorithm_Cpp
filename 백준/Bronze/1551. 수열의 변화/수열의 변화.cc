#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	
	vector<int> v(N);
	for (int i = 0; i < N - 1; ++i) {
		cin >> v[i];
		char tmp;
		cin >> tmp;
	}
	cin >> v[N - 1];

	vector<int> v_new;
	for (int i = 0; i < K; ++i) {
		v_new.resize(v.size() - 1);

		for (int j = 0; j < v.size()-1; ++j) {
			v_new[j] = v[j + 1] - v[j];
		}
		v.swap(v_new);
	}

	for (int i = 0; i < v.size(); ++i) {
		if (i != v.size() - 1) {
			cout << v[i] << ",";
		}
		else
			cout << v[i];
	}
	
}