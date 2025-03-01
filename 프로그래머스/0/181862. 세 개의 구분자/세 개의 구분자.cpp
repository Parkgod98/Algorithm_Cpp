#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> solution(string myStr) {
	vector<string> answer;

	int len = myStr.length();
	int i = 0;
	while (i < len) {
		char c = myStr[i];
		if ((c == 'a' || c == 'b' || c == 'c')) {
			++i;
		}
		else {
			int j = i;
			while (j < len && myStr[j] != 'a' && myStr[j] != 'b' && myStr[j] != 'c')
				j++;
			//cout << "i의 인덱스 : " << i << "j의 인덱스 : " << j << endl;
			answer.push_back(myStr.substr(i, j - i));
			//cout << myStr.substr(i, j - i) << "\n";
			i = j;
		}
	}
    if(answer.size() == 0)
        answer.push_back("EMPTY");
		return answer;
}