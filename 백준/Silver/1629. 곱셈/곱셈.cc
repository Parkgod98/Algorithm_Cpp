#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//
//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()

long long go(long long a, long long b, long long c)
{
	if (b == 1)
		return a % c;
	long long ret = go(a, b / 2, c);
	ret = (ret * ret) % c;
	if (b % 2 == 1)
		ret = (ret * a) % c;
	return ret;
}

int main()
{
	long long a, b, c;
	cin >> a >> b >> c;
	
	long long res;
	res = go(a, b, c);
	cout << res;
}