#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;
int arr[20000010] = { 0 };
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		int n;
		cin >> n;
		++arr[n + 10000000];
	}

	int M;
	cin >> M;
	
	for (int i = 0; i < M; ++i) {
		int n;
		cin >> n;
		cout << arr[n+10000000] << " ";
	}
}