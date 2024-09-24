#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
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
	long long n;
	int b;
	cin >> n >> b;

	string res = "";
	while (n>0) {
		int tmp = n % b;
		if (tmp <= 9)
			res = to_string(tmp)+ res;
		else
			res = (char)(tmp - 10 + 'A') + res;
		n /= b;
	}
	cout << res << "\n";
}
