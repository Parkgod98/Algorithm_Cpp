#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    if(arr.size() == 1)
        return vector<int>(1,-1);
    
    
    vector<int> ans;
    int mn = 2147483000;
    int idx = -1;
    for (int i = 0; i < arr.size(); ++i){
        if(mn > arr[i]){
            idx = i;
            mn = arr[i];
        }
    }
    
    for (int i = 0; i < arr.size(); ++i){
        if(i == idx)
            continue;
        ans.push_back(arr[i]);
    }
    return ans;
}