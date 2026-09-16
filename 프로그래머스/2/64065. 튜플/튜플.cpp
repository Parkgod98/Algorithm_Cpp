#include <string>
#include <vector>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    return a.size() < b.size();
}

vector<int> Parse(int s, int e, string &ss){
    
    vector<int> tmp;
    string t = ss.substr(s,e-s+1);
    
    int num = 0;
    
    int i = 0;
    while(i < t.size()){
        if(!isdigit(t[i])){
            ++i;
            if(num != 0){
                tmp.push_back(num);
                num = 0;
            }
        }
        else{
            num = num*10 + (t[i++] - '0');
        }
    }
    if(num != 0)
        tmp.push_back(num);
    
    return tmp;
}

vector<int> solution(string s) {
    
    vector<vector<int>> v;
    
    int idx = 0;
    int sz = s.size();
    while(idx < s.size()){
        while(idx < sz && !(s[idx] == ',' && s[idx-1] == '}'))
            ++idx;
        
        int start = idx -1;
        while(s[start] != '{')
            --start;
        
        if(idx == sz){
            v.push_back(Parse(start,idx-2,s));
        }
        else
            v.push_back(Parse(start,idx-1,s));
        ++idx;
    }   
    
    sort(v.begin(),v.end(),cmp);
    set<int> st;
    vector<int> ans;
    
    for (vector<int> &it : v){
        for (int &n : it){
            if(st.find(n) == st.end()){
                st.insert(n);
                ans.push_back(n);
            }
        }
    }
    
    
    return ans;
}