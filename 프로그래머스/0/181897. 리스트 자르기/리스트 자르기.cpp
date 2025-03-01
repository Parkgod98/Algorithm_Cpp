#include <string>
#include <vector>
enum {a,b,c};
using namespace std;

vector<int> solution(int n, vector<int> slicer, vector<int> num_list) {
	vector<int> answer;
	switch (n) {
	case 1 :
		for (int i = 0; i <= slicer[b]; ++i)
			answer.push_back(num_list[i]);
		break;
	case 2 :
		for (int i = slicer[a]; i < num_list.size(); ++i)
			answer.push_back(num_list[i]);
		break;
	case 3 :
		for (int i = slicer[a]; i <= slicer[b]; ++i)
			answer.push_back(num_list[i]);
		break;
	case 4 :
		for (int i = slicer[a]; i <= slicer[b]; i+=c)
			answer.push_back(num_list[i]);
		break;
	}
	return answer;
}