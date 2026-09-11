#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

struct KindNum{
    int kind;
    int num;
    
    bool operator<(const KindNum &other) const{
        return num > other.num;
    }
};

int solution(int k, vector<int> tangerine) {
    map<int,int> mp;
    for (int &n : tangerine){
        mp[n]++;
    }
    
    vector<KindNum> v;
    
    for (auto it = mp.begin(); it != mp.end(); ++it){
        v.push_back({it->first,it->second});
    }
    
    sort(v.begin(),v.end());
    
    int ans = 0;
    
    for (auto &it : v){
        
        ++ans;
        while(it.num !=0){
            it.num--;
            --k;
            if(k == 0)
                return ans;
        }
    }
    
}