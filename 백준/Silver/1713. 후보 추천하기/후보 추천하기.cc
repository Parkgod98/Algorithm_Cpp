#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool IsInStudent(vector<tuple<int, int,int>>& v, int n)
{
	for (int i = 0; i < v.size(); ++i) {
		if (get<0>(v[i]) == n) {
			get<1>(v[i])++;
			return true;
		}
	}
	return false;

}

int GetMinIndex(vector<tuple<int, int, int>>& v)
{
	int min = get<1>(v[0]);
	int min_index = 0;
	int old = get<2>(v[0]);
	for (int i = 0; i < v.size(); ++i) {
		if (get<1>(v[i]) < min || (get<1>(v[i]) == min && get<2>(v[i]) > old)) {
			min = get<1>(v[i]);
			min_index = i;
			old = get<2>(v[i]);
		}
	}
	return min_index;
}

void GoDay(vector<tuple<int, int, int>>& v)
{
	for (int i = 0; i < v.size(); ++i) 
		get<2>(v[i])++;
}

int main(void)
{
	int n,recommend_n;
	cin >> n >> recommend_n;

	vector<tuple<int,int,int>> v;  /// (학생, 추천수, 게시 된 일수)
	for (int i = 0; i < recommend_n; ++i) {
		int student;
		cin >> student;
		if (v.size() == n) {
			if (!IsInStudent(v,student)) {
				int idx = GetMinIndex(v);
				get<0>(v[idx]) = student;
				get<1>(v[idx]) = 1;
				get<2>(v[idx]) = 1;
			}
		}
		else {
			if (!IsInStudent(v, student)) 
				v.push_back({ student,1,1 });
		}
		GoDay(v);
	}
	sort(v.begin(), v.end());
	for (tuple<int, int, int> i : v)
		cout << get<0>(i) << " ";
}