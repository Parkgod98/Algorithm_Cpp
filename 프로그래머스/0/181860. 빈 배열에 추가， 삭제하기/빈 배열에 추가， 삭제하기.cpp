#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<bool> flag) {
    vector<int> q;
    
    int sz = flag.size();
    for (int i = 0; i < sz; ++i){
        if(flag[i]){
            for (int k = 0; k < arr[i]*2; ++k)
                q.push_back(arr[i]);
        }
        else{
            for (int k = 0; k < arr[i]; ++k)
                q.pop_back();
        }
    }
    
    return q;
}