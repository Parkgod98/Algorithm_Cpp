#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//
//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()



int main()
{
	// 1 < l < p < v

	// 연속하는 p일중 l일만 사용할수 있고 나는 v일 휴가.
	int l, p, v;
	
	// 5 8 20 - > 연속하는 8일중 5일만 사용 가능
	int i = 1;
	while (1) {
		cin >> l >> p >> v;
		if (l == 0 && p == 0 && v == 0)
			break;
		int n = (v / p) * l;
		v = v - (v / p) * p;
		if (l >= v)
			n += v;
		else
			n += l;
		cout << "Case " << i << ": " << n << "\n";
		i++;
	}
}
