#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <cctype>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int ans = 0;
    
    for (string &s : cities){
        for (char &c : s){
            c = tolower(c);
        }
    }
    
    deque<string> v;
    map<string,int> mp;
    
    for (string &s : cities){
        if(mp.find(s) != mp.end()){
            ans += 1;
            int sz = v.size();
            for (auto it = v.begin(); it != v.end();){
                if(*it == s){
                    v.erase(it);
                    break;
                }
                else
                    ++it;
            }
        }
        else{
            mp[s]++;
            ans += 5;
        }
        v.push_back(s);
        if(v.size() > cacheSize){
            mp[v.front()]--;
            if(mp[v.front()] == 0){
                mp.erase(v.front());
            }
            v.pop_front();
        }
        
    }
    return ans;
}