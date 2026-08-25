#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    int sz = query.size();
    
    int s = 0;
    int e = arr.size() - 1;
    
    for (int i = 0; i < sz; ++i){
        if(i%2 == 0){
            e = s + query[i];
        }
        else{
            s += query[i];
        }
    }
    
    vector<int> ans;
    for (int i = s; i <= e; ++i)
        ans.push_back(arr[i]);
    return ans;
}