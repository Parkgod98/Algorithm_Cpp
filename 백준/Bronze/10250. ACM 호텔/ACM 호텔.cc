//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

int main()
{
	int t;
	cin >> t;
	
	for (int i = 0; i < t; ++i) {
		int h, w, n;
		cin >> h >> w >> n;	
		int res;
		if (n % h == 0) {
			res = h * 100 + n / h ;
		}
		else {
			res = (n % h) * 100 + n / h + 1;
		}
		cout << res << endl;
	}

}
	
