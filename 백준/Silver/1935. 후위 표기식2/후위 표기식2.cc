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

	string s;
	cin >> s;

	int arr[26] = { 0 };
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	
	stack<double> st;
	for (int i = 0; i < s.size(); ++i) {
		if (!isalpha(s[i])) {
			double b = st.top();
			st.pop();
			double a = st.top();
			st.pop();

			double res = 0;
			if (s[i] == '*') {
				res = a * b;
			}
			else if (s[i] == '+') {
				res = a + b;
			}
			else if (s[i] == '/') {
				res = (double)a / b;
			}
			else if (s[i] == '-') {
				res = a - b;
			}
			st.push(res);
		}
		else {
			st.push(arr[s[i] - 'A']);
		}
	}

	double res = st.top();
	cout.precision(2);
	cout << fixed;
	cout << res << "\n";

}  