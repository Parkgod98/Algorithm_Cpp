#include <string>
#include <vector>

using namespace std;
#define EPSILON 0.0000000000001

vector<int> solution(int n, int s) {
    vector<int> ans;
    
    if((double)s/n < 1)
        return {-1};
    
    if(s%n == 0){
        for (int i = 0; i < n; ++i){
            ans.push_back(s/n);
        }
    }
    else{
        if(((double)s/n - s/n) - 0.5 < EPSILON){
            for (int i = 0; i < n/2; ++i){
                ans.push_back(s/n);
            }
            for (int i = 0; i < n/2; ++i)
                ans.push_back(s/n+1);
        }
    }

    return ans;
}