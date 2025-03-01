#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    for (int i = l; i <=r; ++i){
        if (i%5 !=0)
            continue;
        else{
            string s = to_string(i);
            bool only5_0 = true;
            for (char &c : s){
                if (c != '5' && c!= '0'){
                    only5_0 = false;
                    break;
                }
            }
            if(only5_0)
                answer.push_back(i);
        }
    }
    if (answer.size() == 0)
        answer.push_back(-1);
    return answer;
}