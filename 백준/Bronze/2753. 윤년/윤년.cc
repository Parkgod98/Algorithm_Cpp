#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int IsLeap(int y)
{
	return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int y;
	cin >> y;
	cout << IsLeap(y);
}