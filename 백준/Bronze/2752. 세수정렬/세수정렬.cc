#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;
	int mx = max({ a,b,c });
	int mn = min({ a,b,c });
	int mid = a + b + c - mx - mn;

	cout << mn << ' ' << mid << ' ' << mx;
}