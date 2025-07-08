#include <bits/stdc++.h>

using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;

	queue<int> q;
	q.push(S);
	vector<int> visited(F + 1);
	visited[S] = 1;

	while (!q.empty()) {
		int n = q.front();
		q.pop();
		if (n + U <= F && !visited[n+U]) {
			q.push(n + U);
			visited[n + U] = visited[n] + 1;
		}
		if (n - D >= 1 && !visited[n - D]) {
			q.push(n - D);
			visited[n - D] = visited[n] + 1;
		}
	}

	if (!visited[G])
		cout << "use the stairs" << "\n";
	else
		cout << visited[G] -1;
	
}