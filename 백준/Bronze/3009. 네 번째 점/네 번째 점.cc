//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

int main()
{
	map<int, int> xx,yy;
	for (int i = 0; i < 3; ++i) {
		int x, y;
		cin >> x >> y;
		if (xx.find(x) == xx.end())
			xx[x] = 1;
		else
			xx[x] += 1;
		if (yy.find(y) == yy.end())
			yy[y] = 1;
		else
			yy[y] += 1;
	}
	int x, y;
	for (auto it = xx.begin(); it != xx.end(); ++it) {
		if (it->second == 1)
			x = it->first;
	}
	for (auto it = yy.begin(); it != yy.end(); ++it) {
		if (it->second == 1)
			y = it->first;
	}
	cout << x << " " << y << endl;

}
	
