#include <string>
#include <vector>
#include <algorithm>
using namespace std;


string solution(vector<int> food) {
	string answer = "";
	for (int i = 1; i < food.size(); ++i) {
		for (int j = 0; j < food[i] / 2; ++j)
			answer.push_back((char)i +'0');
	}
	answer.push_back('0');
	answer += string(answer.rbegin()+1, answer.rend());
	return answer;
}
