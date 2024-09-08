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
	int h, m, n;
	cin >> h >> m >> n;

	m += n;
	h += m / 60;
	h %= 24;
	m %= 60;
	cout << h << " " << m;
}
