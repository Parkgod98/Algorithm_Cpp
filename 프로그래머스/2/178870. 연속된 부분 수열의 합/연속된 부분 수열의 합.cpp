#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> solution(vector<int> sequence, int k) {
	vector<int> answer;
	vector<int> prefix_sum(sequence.size()+1, 0);

	for (int i = 1; i < prefix_sum.size(); ++i) {
		prefix_sum[i] = prefix_sum[i - 1] + sequence[i-1];
	}
	int i, j;
	i = 0;
	j = 1;
	int min_i, min_j, min_len;
	min_i = min_j = min_len = 1000001;

	while (j < prefix_sum.size() && i < j) {
		int j_1_i = prefix_sum[j] - prefix_sum[i];
		if (j_1_i > k) {
			i++;
		}
		else if (j_1_i < k)
			j++;
		if (j_1_i == k) {
			if (min_len > j - i) {
				min_len = j - i;
				min_j = j;
				min_i = i;
			}
			j++;
		}
	}
	vector<int> v(2);
	v[0] = min_i;
	v[1] = min_j - 1;

	return v;
}