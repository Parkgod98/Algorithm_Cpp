#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    vector<int> answer;
    
    int sz = num_list.size();
    for (int i = 0; i < sz; i +=n){
        answer.push_back(num_list[i]);
    }
    return answer;
}