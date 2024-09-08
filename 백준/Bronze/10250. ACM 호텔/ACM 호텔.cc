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
		string floor, num;
		if (n % h != 0) {
			floor = to_string(n % h);
			num = to_string((n / h) + 1);
		}
		else {
			floor = to_string(h);
			num = to_string((n / h));
		}
		if (num.length() == 1)
			cout << floor + '0' + num << endl;
		else
			cout << floor + num << endl;
	}

}
	
