#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct Group{
    string s;
    int start;
    int remain;
};

vector<string> solution(vector<vector<string>> plans) {
    vector<string> ans;
    
    vector<Group> v;
    for (vector<string> &p : plans){
        Group t;
        t.s = p[0];
        t.start = stoi(p[1].substr(0,2))*60 + stoi(p[1].substr(3));
        t.remain = stoi(p[2].substr(0));
        v.push_back(t);
    }
    
    sort(v.begin(),v.end(),[](Group &a, Group &b){
        return a.start < b.start;
    });
    
    
    stack<Group> st;
    for (auto &g : v){
        cout << g.s << " " << g.start << " " << g.remain << "\n";
    }
    int sz = v.size();
    
    int cur_time = v[0].start;
    for (int i = 1; i < sz; ++i){
        if(cur_time + v[i-1].remain < v[i].start){
            ans.push_back(v[i-1].s);
            cur_time += v[i-1].remain;
            
            while(!st.empty()){
                if((v[i].start -cur_time) - st.top().remain >= 0){
                    ans.push_back(st.top().s);
                    cur_time += st.top().remain;
                    st.pop();
                }
                else{
                    st.top().remain -= (v[i].start - cur_time);
                    cur_time = v[i].start;
                    break;
                }
            }
            cur_time = v[i].start;
        }
        else if(cur_time + v[i-1].remain == v[i].start){
            ans.push_back(v[i-1].s);
            cur_time = v[i].start;
        }
        else if(cur_time + v[i-1].remain > v[i].start){
            v[i-1].remain -= (v[i].start - cur_time);
            st.push(v[i-1]);
            cur_time = v[i].start;
        }
    }
    
    if(!st.empty()){
        if((v[sz-1].start -cur_time) - st.top().remain >= 0){
            ans.push_back(st.top().s);
            cur_time += st.top().remain;
            st.pop();
        }
        else{
            st.top().remain -= (v[sz-1].start - cur_time);
            cur_time += (v[sz-1].start - cur_time);
            ans.push_back(v[sz-1].s);
        }
    }
    else{
        ans.push_back(v[sz-1].s);
    }
    while(!st.empty()){
        ans.push_back(st.top().s);
        st.pop();
    }
    return ans;
}