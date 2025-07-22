#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
int N;

int main() {
	int N;
	cin >> N;

	int a, b, c;
	cin >> a >> b >> c;
	int ma, mb, mc;
	ma = a;
	mb = b;
	mc = c;
	for (int i = 0; i < N - 1; ++i) {
		int na, nb, nc;
		cin >> na >> nb >> nc;
		int ta, tb, tc;
		ta = max(a + na, b + na);
		tb = max(max(a + nb, b + nb), c + nb);
		tc = max(b + nc, c + nc);
		a = ta;
		b = tb;
		c = tc;
		ta = min(ma + na, mb + na);
		tb = min(min(ma + nb, mb + nb), mc + nb);
		tc = min(mb + nc, mc + nc);
		ma = ta;
		mb = tb;
		mc = tc;
	}

	cout << max(a, max(b, c)) << " " << min(ma,min(mb,mc)) << "\n";
}