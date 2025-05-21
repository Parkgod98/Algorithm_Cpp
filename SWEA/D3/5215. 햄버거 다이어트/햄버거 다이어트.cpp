#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, L;
int mx;
void DFS(vector<pair<int, int>> &v, int idx, int limit, int score) {
	if (score > mx && limit <= L)
		mx = score;
	if (limit > L || idx >= v.size()) {
		return;
	}

	DFS(v, idx + 1, limit + v[idx].second, score + v[idx].first);
	DFS(v, idx + 1, limit, score);
}

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> L;
		
		vector<pair<int, int>> v(N);
		for (int i = 0; i < N; ++i) {
			int score, kcal;
			cin >> score >> kcal;
			v[i] = { score,kcal };
		}
		DFS(v,0,0,0);
		cout << "#" << tc << " " << mx << "\n";
		mx = 0;
	}
}