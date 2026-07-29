#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array) {
    vector<int> ans(2);
    
    ans[0] = -1;
    int sz = array.size();
    
    for (int i = 0; i < sz; ++i){
        if(ans[0] < array[i]){
            ans[0] = array[i];
            ans[1] = i;
        }
    }
    return ans;
}