#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> ans;
    
    for (int &n : arr){
        if(n%divisor == 0)
            ans.push_back(n);
    }
    if(ans.size() == 0)
        return vector<int>(1,-1);
    
    sort(ans.begin(),ans.end());
    return ans;
    
}