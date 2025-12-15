#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
#include <set>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

int N, K;
vector<int> v,psum;
map<long long, int> mp;
int main(){
	cin >> N >> K;
	v = vector<int>(N+1);
	for (int i = 0; i < N; ++i)
		cin >> v[i+1];

	psum = vector<int>(N + 1);

	long long res = 0;

	mp[0] = 1;

	for (int i = 1; i <= N; ++i) {
		psum[i] = psum[i - 1] + v[i];
		
		res += mp[psum[i] - K];
		mp[psum[i]]++;
	}

	cout << res << "\n";
}
