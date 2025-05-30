#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int main() {

	int N;
	cin >> N;

	int prev;
	int start, end, mx,n;
	start = end = mx = 0;
	for (int i = 0; i < N; ++i) {
		cin >> n;

		if (i == 0) {
			prev = n;
			start = end = n;
		}
		else if(prev >=n) {
			end = prev;
			if (end - start > mx) {
				mx = end - start;
			}
			start = n;
		}
		prev = n;
	}
	if (prev >= n) {
		end = prev;
		if (end - start > mx) {
			mx = end - start;
		}
	}
	cout << mx << "\n";
}