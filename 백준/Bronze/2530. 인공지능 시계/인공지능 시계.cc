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
	int h, m, s, n;
	cin >> h >> m >> s >> n;

	s += n;
	m = m + (s / 60);
	s %= 60;
	h = h + (m / 60);
	m %= 60;
	h %= 24;

	cout << h << " " << m << " " << s << "\n";
	return 0;
}
