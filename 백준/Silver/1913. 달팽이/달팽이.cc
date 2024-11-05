#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <tuple>
#include <algorithm>
using namespace std;

void PrintV(vector<vector<int>>& v)
{
	for (vector<int> a : v) {
		for (int i : a)
			cout << i << " ";
		cout << endl;
	}
}

int main(void)
{
	int n,target;
	cin >> n >> target;
	
	vector<vector<int>> v(n, vector<int>(n));

	int start = n * n;
	int y, x;
	y = x = 0;
	int i, j;
	i = j = 0;
	while (start > 0) {
		while (y < n && v[y][x] == 0) {
			if (start == target) {
				i = y;
				j = x;
			}
			v[y][x] = start--;
			y++;
		}
		y--;
		x++;
		while (x < n && v[y][x] == 0) {
			if (start == target) {
				i = y;
				j = x;
			}
			v[y][x] = start--;
			x++;
		}
		x--;
		y--;
		while (y >= 0 && v[y][x] == 0) {
			if (start == target) {
				i = y;
				j = x;
			}
			v[y][x] = start--;
			y--;
		}
		y++;
		x--;
		while (x >= 0 && v[y][x] == 0) {
			if (start == target) {
				i = y;
				j = x;
			}
			v[y][x] = start--;
			x--;
		}
		x++;
		y++;
	}
	PrintV(v);
	cout << i+1 << " " << j+1;
}
