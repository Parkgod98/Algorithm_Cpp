#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N;
struct Node {
	int num;
	char value;
	int left, right;
};

vector<Node> v;

void in_order(Node& cur) {
	if (cur.left != 0) 
		in_order(v[cur.left]);
	cout << cur.value;
	if (cur.right != 0)
		in_order(v[cur.right]);
}
int main() {

	for (int tc = 1; tc <= 10; ++tc) {
		cin >> N;
		v = vector<Node>(N+1);
		for (int i = 1; i <= N; ++i) {
			int n;
			char c;
			cin >> n >> c;
			if (n * 2 + 1 <= N) {
				int a, b;
				cin >> a >> b;
				v[i] = { n,c,a,b };
			}
			else if (n * 2 == N) {
				int a;
				cin >> a;
				v[i] = { n,c,a,0 };
			}
			else
				v[i] = { n,c };
		}

		cout << "#" << tc << " ";
		in_order(v[1]);
		cout << "\n";
	}
}
