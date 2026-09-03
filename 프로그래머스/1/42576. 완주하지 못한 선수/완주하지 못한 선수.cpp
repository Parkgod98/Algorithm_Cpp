#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    map<string,int> mp;
    
    for (string &s : completion)
        mp[s] +=1;
    
    for (string &s : participant){
        if(mp.find(s) == mp.end())
            return s;
        else{
            mp[s]--;
            if(mp[s] < 0)
                return s;
        }
    }
}