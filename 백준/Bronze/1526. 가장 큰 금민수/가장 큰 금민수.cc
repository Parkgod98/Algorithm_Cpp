#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
vector<string> v;
void Make(string s, int depth) {
	if(s!= "")
		v.push_back(s);
	if (depth == 6)
	{
		return;
	}
	Make(s + "4", depth + 1);
	Make(s + "7", depth + 1);

}

int main() {
	int N;
	cin >> N;
	Make("",0);

	int mx = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (stoi(v[i]) <= N && mx < stoi(v[i])) {
			mx = stoi(v[i]);
		}
	}
	cout << mx << "\n";
}