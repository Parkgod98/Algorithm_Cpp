#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

string Get8(int n){
	string res = "";

	while (n != 0) {
		res = to_string(n % 2) +res;
		n /= 2;
	}

	while (res.size() < 3)
		res = "0" + res;

	return res;
}

int main() {
	string s;
	cin >> s;
	if (s == "0") {
		cout << 0;
		return 0;
	}
	string res = "";
	for (int i = 0; i < s.size(); ++i) {
		res += Get8(s[i]-'0');
	}

	int idx = 0;
	while (res[idx] == '0')
		++idx;

	for (int i = idx; i < res.size(); ++i)
		cout << res[i];

}