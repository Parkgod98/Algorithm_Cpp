#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
using namespace std;

int main() {
	int n;
	cin >> n;

	int res = -1;
	if (n % 5 == 0)
		res = n / 5;
	else {
		int money = n;
		money = n - (n/5) *5;
		
		if (money % 2 == 0) {
			res = n / 5 + money / 2;
		}
		else if(n/5 >= 1) {
			money = n - (n / 5 - 1) * 5;
			res = money / 2 + (n / 5 - 1);
		}
	}

	cout << res << "\n";
}