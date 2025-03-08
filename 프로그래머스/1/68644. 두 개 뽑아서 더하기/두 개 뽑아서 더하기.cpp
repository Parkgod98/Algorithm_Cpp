#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;


vector<int> solution(vector<int> numbers) {
	vector<int> answer;
	map<int, bool> mp;
	for (int i = 0; i < numbers.size(); ++i) {
		for (int j = i + 1; j < numbers.size(); ++j) {
			if (mp.find(numbers[i] + numbers[j]) == mp.end()) {
				mp[numbers[i] + numbers[j]] = true;
			}
		}
	}
	answer.reserve(mp.size());
	for (auto& it : mp) {
		answer.emplace_back(it.first);
	}
	return answer;
}