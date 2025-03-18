#include <bits/stdc++.h>
using namespace std;

#define MX 1000005
char dat[MX];
int pre[MX], nxt[MX];
int unused = 1;
void traverse();

void insert(int addr, char c) {
	dat[unused] = c;
	pre[unused] = addr;
	nxt[unused] = nxt[addr];

	if(nxt[addr] !=-1)
		pre[nxt[addr]] = unused;
	nxt[addr] = unused;
	++unused;
}

void erase(int addr) {

	nxt[pre[addr]] = nxt[addr];
	if(nxt[addr] != -1)
		pre[nxt[addr]] = pre[addr];
}

void traverse() {
	int cur = nxt[0];
	while(cur != -1) {
		cout << dat[cur];
		cur = nxt[cur];
	}
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	fill(pre, pre + MX, -1);
	fill(nxt, nxt + MX, -1);

	string s;
	cin >> s;
	for(int i = 0; i < s.size(); ++i) {
		insert(i, s[i]);
	}

	int n;
	cin >> n;
	cin.ignore();
	int cur = s.size();
	int sz = s.size();
	for(int i = 0; i < n; ++i) {
		string com;
		getline(cin, com);

		if(com[0] == 'L') {
			if(pre[cur] !=-1)
				cur = pre[cur];
		}
		else if(com[0] == 'D') {
			if(nxt[cur] !=-1)
				cur = nxt[cur];

		}
		else if(com[0] == 'B') {
			if(cur != 0) {
				erase(cur);
				cur = pre[cur];
			}
		}
		else {
			char tar = com[2];
			insert(cur, tar);
			cur = unused - 1;
		}
	}
	traverse();

}