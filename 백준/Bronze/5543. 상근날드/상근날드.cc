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
	vector<int> hambug, cola;
	
	for (int i = 0; i < 5; ++i) {
		int n;
		cin >> n;
		if (i < 3)
			hambug.push_back(n);
		else
			cola.push_back(n);
	}
	sort(hambug.begin(), hambug.end());
	sort(cola.begin(), cola.end());

	cout << hambug[0] + cola[0] - 50 << "\n";
}
