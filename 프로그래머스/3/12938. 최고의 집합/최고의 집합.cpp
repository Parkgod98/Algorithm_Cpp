#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    
    if(s/n <= 0)
        return {-1};
    
    vector<int> ans;
    for (int i = 0; i < n; ++i){
        ans.push_back(s/n);
    }
    
    
    int k = s%n;
    
    int idx = ans.size()-1;
    while(k > 0){
        ans[idx] += 1;
        --k;
        idx--;
    }
    return ans;
}