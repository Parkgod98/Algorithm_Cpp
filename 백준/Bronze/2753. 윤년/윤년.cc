#include <iostream>

using namespace std;

int IsYoon(int year) {
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		return 1;
	return 0;
}

int main()
{
	int year;
	
	cin >> year;
	cout << IsYoon(year);
}