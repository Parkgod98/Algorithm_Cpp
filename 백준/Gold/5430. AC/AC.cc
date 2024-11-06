#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <tuple>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

deque<int> init(string arr)
{
	deque<int> li;
	string temp = "";
	for (int i = 1; i < arr.size(); i++)
	{
		if ((arr[i] == ',' || arr[i] == ']') && temp != "")
		{
			li.push_back(stoi(temp));
			temp = "";
		}
		else temp += arr[i];
	}
	return li;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		string func;
		cin >> func;

		int n;
		cin >> n;
		string num;
		cin >> num;

		int error_flag = 0;
		deque<int> v;
		v = init(num);
		int r_count = 0;
		int d_count = 0;
		for (char c : func) {
			if (c == 'D')
				d_count++;
		}
		if (d_count > n) {
			cout << "error" << "\n";
			continue;
		}
		for (char c : func) {
			if (c == 'R')
				r_count++;
			else if (c == 'D') {
				if (r_count % 2 == 0)
					v.pop_front();
				else
					v.pop_back();
			}
		}
		if(r_count%2)
			reverse(v.begin(),v.end());
		cout << "[";
		for (int j = 0; j < v.size(); ++j) {
			if (j != v.size() - 1)
				cout << v[j] << ",";
			else
				cout << v[j];
		}
		cout << "]" << "\n";

	}
}
