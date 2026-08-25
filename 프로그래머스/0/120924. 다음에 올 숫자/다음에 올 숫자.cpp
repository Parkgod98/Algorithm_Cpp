#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int ans = 0;
    
    double d = 0;
    int sz = common.size();
    
    if(common[1] - common[0] == common[2] - common[1]){
        d = common[1] - common[0];
        ans = common[common.size()-1] + d;
    }
    else {
        d = common[1]/common[0];
        ans = common[common.size()-1]*d;
    }
    
    return ans;
}