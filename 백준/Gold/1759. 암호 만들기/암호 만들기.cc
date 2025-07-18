#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int L, C;
vector<char> v;
vector<char> ans;
int za, mo;

void Comb(int idx) {
	if (ans.size() == L && za >= 2 && mo >= 1) {
		for (char &c : ans)
			cout << c;
		cout << "\n";
		return;
	}

	for (int i = idx; i < C; ++i) {
		ans.push_back(v[i]);
		if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u')
			mo++;
		else
			za++;
		Comb(i + 1);
		ans.pop_back();
		if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u')
			mo--;
		else
			za--;
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
