#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//
//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
/*
* 모음(a,e,i,o,u) 하나 이상 포함
* 모음 or 자음 3번 연속 오면 안됨.
* 같은 글자 연속 두번 오면 안됨 but ee나 oo는 가능.
*/

bool IsMo(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	return false;
}

bool IsJa(char c)
{
	if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u')
		return true;
	return false;
}

bool MoCheck(string s)
{
	int len = s.length();
	for (int i = 0; i < len; ++i) {
		if (IsMo(s[i]))
			return true;
	}
	return false;
}

bool SequenceCheck(string s)
{
	int len = s.length();
	int mo_check = 0;
	int ja_check = 0;
	for (int i = 0; i < len; ++i) {
		if (IsMo(s[i])) {
			mo_check++;
			ja_check = 0;
		}
		else if (IsJa(s[i])) {
			ja_check++;
			mo_check = 0;
		}
		if (mo_check == 3 || ja_check == 3)
			return false;
	}
	return true;
}

bool DoubleCheck(string s)
{
	int len = s.length();
	char pc = ' ';
	for (int i = 0; i < len; ++i) {
		char cur = s[i];
		if (cur == pc && cur != 'e' && cur != 'o')
			return false;
		pc = cur;
	}
	return true;
}
bool Check(string s)
{
	bool moflag = MoCheck(s);
	bool seflag = SequenceCheck(s);
	bool dflag = DoubleCheck(s);

	return moflag && seflag && dflag;
}
int main()
{
	while (1) {
		string s;
		cin >> s;
		if (s == "end")
			break;
		if (Check(s))
			cout << "<" << s << "> is acceptable." << "\n";
		else
			cout << "<" << s << "> is not acceptable." << "\n";
	}
}
