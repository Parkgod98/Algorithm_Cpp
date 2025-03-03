#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
	
	for (vector<int>& v : queries) {
		for (int s = v[0]; s <= v[1]; ++s) {
			if (s % v[2] == 0)
				arr[s] += 1;
		}
	}
	return arr;
}