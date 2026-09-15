#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    
    map<string,int> mp;
    vector<int> visited(21);
    for (string &s : phone_book){
        visited[s.size()] = 1;
        mp[s] = 1;
    }
    
    for (string &s : phone_book){
        
        for (int i = 1; i <= 20; ++i){
            if(visited[i]){
                string ss = s.substr(0,i);
                auto it = mp.find(ss);
                if(it != mp.end() && it->first != s)
                    return false;
            }
        }
    }
    return true;
}