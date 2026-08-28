#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int sz = number.size();
    
    int cnt = 0;
    for (int i = 0; i < sz; ++i){
        for (int j = i + 1; j < sz; ++j){
            for (int k = j +1; k < sz; ++k){
                if(number[i] + number[j] + number[k] == 0)
                    ++cnt;
            }
        }
    }
    return cnt;
}