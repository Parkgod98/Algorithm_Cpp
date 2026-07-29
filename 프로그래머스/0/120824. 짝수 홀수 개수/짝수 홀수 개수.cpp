#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer(2);
    for (int &n : num_list){
        if(n%2 == 1)
            answer[1]++;
        else
            answer[0]++;
    }
    return answer;
}