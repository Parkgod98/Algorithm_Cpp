#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int main() {
	int N;
	cin >> N;

	stack<int> st;
	int target = 1;
	for (int i = 0; i < N; ++i) {
		int n;
		cin >> n;

		if (n == target) {
			target++;
		}
		else {
			st.push(n);
		}

		while (!st.empty() && st.top() == target) {
			st.pop();
			++target;
		}
	}

	if (st.empty())
		cout << "Nice";
	else
		cout << "Sad";
	
}  