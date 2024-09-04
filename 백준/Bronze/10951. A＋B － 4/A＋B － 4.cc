#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main()
{

	int a, b;

	while (cin >> a >> b) {
		cout << a + b << "\n";
	}

	//while (!(cin >> a >> b).eof()) {
	//	cout << a + b << "\n";
	//}

	//while (scanf("%d %d", &a, &b) != -1) {
	//	cout << a + b << "\n";
	//}

	return 0;
}