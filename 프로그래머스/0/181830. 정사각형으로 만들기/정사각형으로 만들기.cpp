#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
	int r_size = arr.size();
	int c_size = arr[0].size();
	if (r_size == c_size)
		return arr;
	else if (r_size > c_size) {
		for (int i = 0; i < r_size; ++i) {
			for (int j = 0; j < r_size - c_size; ++j)
				arr[i].push_back(0);
		}
	}
	else {
		for (int i = 0; i < c_size - r_size; ++i) {
			arr.push_back(vector<int>(c_size, 0));
		}
	}
	return arr;
}