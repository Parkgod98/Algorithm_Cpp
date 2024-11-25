#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void CalPrint(int n) {
	int q, d, nn;
	q = n / 25;
	n %= 25;
	d = n / 10;
	n %= 10;
	nn = n / 5;
	n %= 5;
	cout << q << " " << d << " " << nn << " " << n << "\n";
}

int main()
{
	int n;
	cin >> n;
	
	for (int i = 0; i < n; ++i) {
		int c;
		cin >> c;
		CalPrint(c);
	}

}