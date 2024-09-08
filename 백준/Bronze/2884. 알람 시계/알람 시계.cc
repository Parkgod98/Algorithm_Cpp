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
	int h, m;

	cin >> h >> m;
	m -= 45;
	if (m < 0) {
		h -= 1;
		if (h < 0)
			h = 23;
		m += 60;
	}
	cout << h << " " << m;
}
