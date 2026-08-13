#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> emergency) {
    int sz = emergency.size();
    vector<int> ans(sz,1);
    
    for (int i = 0; i < sz; ++i){
        for (int j = 0; j < sz; ++j){
            if(i == j)
                continue;
            if(emergency[i] < emergency[j])
                ans[i]++;
        }
    }
    return ans;
}