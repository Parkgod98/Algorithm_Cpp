#include <iostream>
#include <vector>
#include <map>

using namespace std;

enum Direction {R,L,B,T,RT,LT,RB,LB,SIZE};

map<string, Direction> m = { {"R",R},{"L",L} ,{"B",B} ,{"T",T} ,{"RT",RT} ,{"LT",LT} ,{"RB",RB} ,{"LB",LB} };

// 오,왼,아래,위,오위대각,왼위대각,오아래대각,왼아래대각
int dy[8] = { 0,0,1,-1,-1,-1,1,1 };
int dx[8] = { 1,-1,0,0 ,1,-1,1,-1};

void Move(vector<vector<int>>& v, string move, int &king_y, int &king_x, int &stone_y, int &stone_x)
{
	int kny = king_y + dy[m[move]];
	int knx = king_x + dx[m[move]];
	int sny = stone_y + dy[m[move]];
	int snx = stone_x + dx[m[move]];
	if (kny < 0 || knx < 0 || kny >= 8 || knx >= 8)
		return;
	else {
		if (kny == stone_y && knx == stone_x) {
			if (sny < 0 || snx < 0 || sny >= 8 || snx >= 8)
				return;
			v[sny][snx] = 2;
			v[stone_y][stone_x] = 0;
			stone_y = sny;
			stone_x = snx;
		}
		v[kny][knx] = 1;
		v[king_y][king_x] = 0;
		king_y = kny;
		king_x = knx;
	}
	
}

int main(void)
{
	string king, stone;
	int n;
	cin >> king >> stone >> n;

	int king_x, king_y, stone_x, stone_y;
	king_x = king[0] - 'A';
	king_y = 8 - (king[1]-'0');
	stone_x = stone[0] - 'A';
	stone_y = 8 - (stone[1]-'0');

	vector<vector<int>> v(8,vector<int>(8));
	v[king_y][king_x] = 1;
	v[stone_y][stone_x] = 2;

	for (int i = 0; i < n; ++i) {
		string move;
		cin >> move;
		Move(v, move, king_y, king_x, stone_y, stone_x);
	}
	cout << (char)(king_x + 'A') << 8 - king_y << "\n";
	cout << (char)(stone_x + 'A') << 8 - stone_y << "\n";
}