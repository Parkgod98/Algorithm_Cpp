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
	vector<int> v;
	for (int i = 0; i < 3; ++i) {
		int n;
		cin >> n;
		v.push_back(n);
	}
	int sum = 0;
	for (int i : v)
		sum += i;
	if (sum != 180)
		cout << "Error" << "\n";
	else {
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		if (v.size() == 3)
			cout << "Scalene" << "\n";
		else if (v.size() == 2)
			cout << "Isosceles" << "\n";
		else
			cout << "Equilateral" << "\n";
	}
}
