#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> ans;

    for (left; left <= right; ++left){
        int y = left/n;
        int x = left%n;
        
        ans.push_back(max(y,x)+1);
    }
    return ans;
}