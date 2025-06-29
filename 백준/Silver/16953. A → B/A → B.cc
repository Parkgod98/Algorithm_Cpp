#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
long long A, B;
#define CANT 2000000000

int cnt = CANT;
void DFS(long long cur,int depth) {
	if (cur > B)
		return;
	if (cur == B) {
		cnt = min(depth,cnt);
	}
	if (cur * 10 + (long long)1 <= (long long)1000000000) {
		DFS(cur * 10 + 1,depth+1);
	}
	if (cur * 2 <= (long long)1000000000) {
		DFS(cur * 2,depth+1);
	}
}
int main() {
	cin >> A >> B;

	DFS(A,0);

	if (cnt == CANT)
		cout << -1 << "\n";
	else
		cout << cnt + 1;
}