#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int L, C;
vector<char> v;
vector<char> ans;

bool Check() {
	int za = 0;
	int mo = 0;

	for (int i = 0; i < L; ++i) {
		if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u')
			++mo;
		else
			za++;
	}
	if (za >= 2 && mo >= 1)
		return true;
	return false;
}
void Comb(int idx) {
	if (ans.size() == L) {
		if (Check()) {
			for (char &c : ans)
				cout << c;
			cout << "\n";
		}
		return;
	}

	for (int i = idx; i < C; ++i) {
		ans.push_back(v[i]);
		Comb(i + 1);
		ans.pop_back();
	}
}
int main() {
	cin >> L >> C;
	v = vector<char>(C);
	for (int i = 0; i < C; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());

	Comb(0);
}
