#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <string>
using namespace std;
int N, K;
bool Flag = false;
void move(int n, int start, int end) {
	++K;
	if (Flag) {
		cout << start << " " << end << "\n";
	}
}
void Hanoi(int SZ, int from, int to, int inter) {
	if (SZ == 1) {
		move(SZ, from, to);
	}
	else {
		Hanoi(SZ - 1, from, inter, to);
		move(SZ, from, to);
		Hanoi(SZ - 1, inter, to, from);
	}
}
int main() {
	cin >> N;
	
	Hanoi(N, 1, 3, 2);
	Flag = true;
	cout << K << "\n";
	Hanoi(N, 1, 3, 2);
}