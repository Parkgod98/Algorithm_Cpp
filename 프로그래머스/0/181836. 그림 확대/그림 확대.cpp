#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> picture, int k) {
	vector<string> answer;
	int len = picture[0].size();
	for (string& s : picture) {
		string tmp = "";
		for (int i = 0; i < len; ++i) {
			for (int j = 0; j < k; ++j)
				tmp.push_back(s[i]);
		}
        for (int i = 0; i < k; ++i)
		    answer.push_back(tmp);
	}
		return answer;
}