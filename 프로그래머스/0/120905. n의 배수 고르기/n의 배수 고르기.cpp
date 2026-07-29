#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> numlist) {
    int sz = numlist.size();
    
    vector<int> ans;
    for (int i = 0; i < sz; ++i){
        if(numlist[i]%n == 0)
            ans.push_back(numlist[i]);
    }
    return ans;
}