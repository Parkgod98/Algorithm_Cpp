#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Group{
    vector<string> g;
    int weight = 0;
};

int solution(vector<int> picks, vector<string> minerals) {
    int total = 0;
    for (int &n : picks)
        total += n;
    
    vector<Group> v;
    int sz = minerals.size();
    int cnt = 0;
    for (int i = 0; i < sz; i += 5){
        if(cnt < total){
            Group t;
            int sum = 0;
            for (int j = i; j < i + 5 && j < sz; ++j){
                t.g.push_back(minerals[j]);
                if(minerals[j] == "diamond"){
                    sum += 25;
                }
                else if(minerals[j] == "iron"){
                    sum += 5;
                }
                else{
                    sum += 1;
                }
            }
            t.weight = sum;
            ++cnt;
            v.push_back(t);
        }
    }
    
    sort(v.begin(),v.end(),[&](Group &a, Group &b){
        return a.weight > b.weight;
    });
    
    
    int ans = 0;
    for (Group &t : v){
        if(picks[0] > 0){
            picks[0]--;
            ans += t.g.size();
        }
        else if(picks[1] > 0){
            picks[1]--;
            
            for (auto &s : t.g){
                if(s == "diamond")
                    ans += 5;
                else
                    ans +=1;
            }
        }
        else if(picks[2] > 0){
            picks[2]--;
            
            for (auto &s : t.g){
                if(s == "diamond")
                    ans += 25;
                else if(s == "iron")
                    ans += 5;
                else
                    ans +=1;
            }
        }
    }
        
    return ans;
    

}