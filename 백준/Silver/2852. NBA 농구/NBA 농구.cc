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
typedef long long ll;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//
//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()

int GetSec(string time)
{
	int min = stoi(time.substr(0, time.find(':')));
	int sec = stoi(time.substr(3));
	int cur_sec = min * 60 + sec;
	return cur_sec;
}

void PrintTime(int a, int b)
{
	string am, as, bm, bs;
	am = to_string(a / 60);
	as = to_string(a % 60);
	bm = to_string(b / 60);
	bs = to_string(b % 60);
	if (am.size() == 1)
		am = "0" + am;
	if (as.size() == 1)
		as = "0" + as;
	if (bm.size() == 1)
		bm = "0" + bm;
	if (bs.size() == 1)
		bs = "0" + bs;
	cout << am << ":" << as << "\n" << bm << ":" << bs;
}

int main()
{
	int n;
	cin >> n;

	int a_score, b_score;
	a_score = b_score = 0;

	bool af, bf;
	af = bf = 0;
	int at, bt;
	at = bt = 0;
	int ares, bres;
	ares = bres = 0;
	for (int i = 0; i < n; ++i) {
		int score;
		string time;
		cin >> score >> time;

		if (score == 1)
			a_score++;
		else
			b_score++;

		int sec = GetSec(time);
		if (!af && a_score > b_score) {
			af = 1;
			bf = 0;
			at = sec;
		}
		else if (!bf && a_score < b_score) {
			bf = 1;
			af = 0;
			bt = sec;

		}
		else if (a_score == b_score) {
			if (af) {
				ares += (sec - at);
			}
			else if (bf)
				bres += (sec - bt);
			af = bf = 0;
		}
	}
	if (af) {
		ares += (48*60 - at);
	}
	else if (bf)
		bres += (48*60 - bt);

	PrintTime(ares, bres);
}
