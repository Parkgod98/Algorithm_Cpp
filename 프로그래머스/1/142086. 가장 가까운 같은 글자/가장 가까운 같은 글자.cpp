#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;


vector<int> solution(string s) {
	map<char, int> char_index;
	vector<int> answer;
	answer.reserve(s.size());

	for (int i = 0; i < s.size(); ++i) {
		if (char_index.find(s[i]) == char_index.end()) {
			answer.push_back(-1);
			char_index[s[i]] = i;
		}
		else {
			answer.push_back(i - char_index[s[i]]);
			char_index[s[i]] = i;
		}
	}
	return answer;
}

template <typename T>

void PrintV(const vector<T>& v) {
	cout << "[ ";
	for (const auto& elem : v) {
		cout << elem << " ";
	}
	cout << "]" << "\n";
}

int main(void) {
	PrintV(solution("banana"));
}