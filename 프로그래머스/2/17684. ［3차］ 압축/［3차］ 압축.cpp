#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    vector<int> ans;
    map<string,int> mp;
    
    for (int i = 0; i < 26; ++i){
        string t = "";
        t += (i+'A');
        mp[t] = i+1;
    }
    
    
    int sz = msg.size();
    
    int last = 27;
    int i = 0;
    while(i < sz){
        string start = "";
        start += msg[i];
        int nxt = i+1;
        
        while(nxt < sz && mp.find(start) != mp.end()){
            start += msg[nxt++];
        }

        if(mp.find(start) == mp.end()){       
            mp[start] = last++;        
            start.pop_back();
        }
        ans.push_back(mp[start]);
        i+= (int)start.size();
    }    
    
    return ans;
}