#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

void PrintV(vector<int> &v) {
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << "\n";
}

int main() {
	vector<int> v(5);
	for (int i = 0; i < 5; ++i)
		cin >> v[i];

	for (int i = 0; i < 5; ++i) {
		for (int j = 1; j < 5; ++j) {
			if (v[j - 1] > v[j]) {
				swap(v[j - 1], v[j]);
				PrintV(v);
			}
		}
		if (v[0] == 1 && v[1] == 2 && v[2] == 3 && v[4] == 5)
			break;
	}

}