#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string s)
{
    int sz = s.size();
    vector<int> mx(sz,1);
    
    int ans = 1;
    for (int i = 0; i < sz; ++i){
        
        int l = i - 1;
        int r = i + 1;
        
        while(l >= 0 && r < sz){
            if(s[l] == s[r]){
                mx[i] += 2;
            }
            else{
                break;
            }
            --l;
            ++r;
        }
        
        l = i;
        r = i +1;
        int cnt = 0;
        while(l >= 0 && r < sz){
            if(s[l] == s[r]){
                cnt += 2;
            }
            else
                break;
            --l;
            ++r;
        }
        mx[i] = max(mx[i],cnt);
        
        ans = max(ans,mx[i]);
    }
    
    return ans;
}