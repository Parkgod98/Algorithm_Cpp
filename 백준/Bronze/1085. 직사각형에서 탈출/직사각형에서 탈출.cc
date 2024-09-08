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
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	cout << min(min(x,y),min(w - x, h - y));
}
