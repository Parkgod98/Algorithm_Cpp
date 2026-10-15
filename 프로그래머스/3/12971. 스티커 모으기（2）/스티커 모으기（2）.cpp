#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> sticker)
{
    
    
    int sz = sticker.size();
    if(sz == 1)
        return sticker[0];
    vector<int> dp1(sz,0);
    vector<int> dp2(sz,0);
    int mx = 0;
    
    
    for (int i = 0; i < sz-1; ++i){
        if(i-2>=0)
            dp1[i] = max(dp1[i-1],dp1[i-2]+sticker[i]);
        else if(i-1 >= 0){
            dp1[i] = max(dp1[i-1],sticker[i]);
        }
        else{
            dp1[i] = sticker[i];
        }
        mx = max(mx,dp1[i]);
    }
    
    for (int i = 1; i < sz; ++i){
        if(i-2 >= 0){
            dp2[i] = max(dp2[i-1],dp2[i-2]+sticker[i]);
        }
        else if(i-1 >= 0){
            dp2[i] = max(dp2[i-1],sticker[i]);
        }
        mx = max(mx,dp2[i]);
    }
    return mx;
}