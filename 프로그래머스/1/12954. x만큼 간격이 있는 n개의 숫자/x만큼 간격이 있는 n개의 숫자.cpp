#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> ans;
    
    for (int i = 0; i < n; ++i){
        ans.push_back(x*(i+1));
    }
    
    return ans;
}