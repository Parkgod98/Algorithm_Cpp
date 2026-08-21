#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    int i = 0;
    int sz = arr.size();
    vector<int> stk;
    while(i < sz){
        if(stk.empty()){
            stk.push_back(arr[i]);
            ++i;
        }
        else{
            if(stk[stk.size()-1] == arr[i]){
                stk.pop_back();
                ++i;
            }
            else{
                stk.push_back(arr[i]);
                ++i;
            }
        }
    }
    
    if(stk.size() == 0)
        stk.push_back(-1);
    return stk;
}