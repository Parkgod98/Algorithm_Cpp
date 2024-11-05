#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <tuple>
#include <algorithm>
using namespace std;

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

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
	int y = -1, x = 0;
	int i, j;
	i = j = 0;
	int dir = 0;
	while (start > 0) {
		
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n || v[ny][nx] != 0) {
			dir = (dir + 1) % 4;
			ny = y + dy[dir];
			nx = x + dx[dir];
		}
		if (start == target) {
			i = ny;
			j = nx;
		}
		v[ny][nx] = start--;
		y = ny;
		x = nx;
	}
	PrintV(v);
	cout << i+1 << " " << j+1;
}
