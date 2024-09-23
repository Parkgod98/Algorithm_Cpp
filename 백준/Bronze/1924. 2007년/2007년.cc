//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
using namespace std;
enum DAY {SUN,MON,TUE,WED,THU,FRI,SAT,SIZE};


//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()

int main()
{
	int x, y;
	cin >> x >> y;
	
	string days[SIZE] = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
	int month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int shift = 0;
	for (int i = 1; i < x; ++i) {
		shift += month[i];
	}
	shift += y;
	cout << days[shift % SIZE] << "\n";
}