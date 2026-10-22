#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> a) {
    
    vector<int> mn(a.size(),1100000000);
    vector<int> rmn(a.size(),1100000000);
    
    int smn = 1100000000;
    int idx = 0;
    
    for (int i = 0; i < a.size(); ++i){
        if(i - 1 >= 0)
            mn[i] = min(mn[i-1],a[i]);
        else if(i == 0)
            mn[i] = a[i];
        
        if(a[i] < smn){
            smn = a[i];
            idx = i;
        }
    }
    
    for (int i = a.size()-1; i >= 0; --i){
        if(i +1 < a.size())
            rmn[i] = min(rmn[i+1],a[i]);
        else
            rmn[i] = a[i];
    }
    
    int ans = 0;
    for (int i = 0; i < idx; ++i){
        if(mn[i] == a[i])
            ++ans;
    }
    for (int i = a.size()-1; i > idx; --i){
        if(rmn[i] == a[i]){
            ++ans;
        }
    }
    
    return ans+1;
}