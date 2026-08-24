#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> dots) {
    int mx_x,mn_x,mx_y,mn_y;
    mx_x = mn_x = mx_y = mn_y = -500;
    for (vector<int> &v : dots){
        mx_x = max(v[0],mx_x);
        mx_y = max(v[1],mx_y);
        
        if(mn_x == -500)
            mn_x = v[0];
        mn_x = min(v[0],mn_x);
        if(mn_y == -500)
            mn_y = v[1];
        mn_y = min(v[1],mn_y);
    }
    
    int ans = abs(mx_x-mn_x) * abs(mx_y-mn_y);
    return ans;
}