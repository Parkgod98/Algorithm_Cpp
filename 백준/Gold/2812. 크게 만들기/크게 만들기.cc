#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
using namespace std;
int N, K;

string s;
int main(){
	cin >> N >> K;
	cin >> s;

	stack<char> st;
	stack<char> st2;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++)
	{
		while (!st.empty() && cnt < K && s[i] > st.top())
		{
			cnt++;
			st.pop();
		}
		st.push(s[i]);
	}
	while (cnt < K)
	{
		cnt++;
		st.pop();
	}
	//스택 순서 거꾸로 바꿔준 후 출력
	while (!st.empty())
	{
		st2.push(st.top());
		st.pop();
	}
	while (!st2.empty())
	{
		cout << st2.top();
		st2.pop();
	}
	return 0;
}