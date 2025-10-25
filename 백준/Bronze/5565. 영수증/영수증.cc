#include <iostream>
using namespace std;

int main()
{
	int tot = 0;
	int book[9] = { 0 };
	int sum = 0;

	cin >> tot;
	for (int i = 0; i < 9; i++)
	{
		cin >> book[i];
		sum += book[i];
	}
	cout << tot - sum;
}