#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> ans;
    
    int sy = left/n;
    int sx = left%n;
    int ey = right/n;
    int ex = right%n;
    
    int x = sx;
    for (int y = sy; y <= ey; ++y){
        
        if(y == ey){
            while(x <= ex){
                int mx = max(y,x);
                ans.push_back(mx+1);
                ++x;
            }
        }
        else{
            while(x < n){
                int mx = max(y,x);
                ans.push_back(mx+1);
                ++x;
            }
        }
        x%=n;
    }
    return ans;
}