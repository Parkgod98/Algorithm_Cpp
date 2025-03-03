#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
	int answer = 0;

	map<int,int> mp;
	
	for (int i = 0; i < attendance.size(); ++i) {
		if (attendance[i]) {
			mp[rank[i]] = i;
		}
	}
    
	int k = 10000;
	for (auto &m : mp) {
		answer += k * m.second;
		k /= 100;
	}
		return answer;
}