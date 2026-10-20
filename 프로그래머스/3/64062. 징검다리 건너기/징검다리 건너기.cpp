#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> stones, int k) {
    int mn = 1;
    int mx = 0;
    
    for (int &s : stones){
        mn = min(mn,s);
        mx = max(mx,s);
    }
    
    int ans = 0;
    
    while(mn <= mx){
        int mid = (mn + mx) / 2;
        int cnt = 0;
        bool can = true;
        
        for (int i = 0; i < stones.size(); ++i){
            if(stones[i] - mid < 0){
                ++cnt;
            }
            else{
                cnt = 0;
            }
            
            if(cnt >= k){
                can = false;
                break;
            }
        }
        
        if(can){
            ans = mid;
            mn = mid + 1;
        }
        else{
            mx = mid - 1;
        }

    }
    
    return ans;
}