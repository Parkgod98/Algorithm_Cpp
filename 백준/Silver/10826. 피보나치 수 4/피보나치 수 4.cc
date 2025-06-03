#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string Plus(string a, string b) { // 넣을때 애초에 b가 큰걸 넣는다. v[i-2], v[i-1]

	string res = "";

	int carry = 0;
	
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	for (int i = 0; i < a.size(); ++i) {
		int sum = (a[i] - '0') + (b[i] - '0') + carry;
		if (carry == 1)
			carry = 0;
		if (sum >= 10) {
			carry = 1;
			sum -= 10;
		}
		res += (sum + '0');
	}

	for (int i = a.size(); i < b.size(); ++i) {
		int sum = b[i] - '0' + carry;
		if (carry == 1)
			carry = 0;
		if (sum >= 10) {
			carry = 1;
			sum -= 10;
		}
		res += (sum + '0');
	}
	if (carry)
		res += (carry + '0');
	reverse(res.begin(), res.end());

	return res;
}

int main() {
	int n;
	cin >> n;

	if (n == 0)
		cout << 0;
	else if (n == 1 || n == 2)
		cout << 1;
	else {
		string pprev, prev;
		pprev = "1";
		prev = "1";
		string cur;
		for (int i = 3; i <= n; ++i) {
			cur = Plus(pprev, prev);
			pprev = prev;
			prev = cur;
		}
		cout << cur;
	}

}
