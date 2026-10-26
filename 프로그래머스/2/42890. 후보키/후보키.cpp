#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
vector<int> selected;
vector<vector<int>> ans;

void Comb(int cur, vector<vector<string>> &relation, int len){
    
    if(selected.size() == len){
        
        for (vector<int> &v : ans){
            bool included = true;
            
            for (int col : v){
                if(find(selected.begin(),selected.end(),col) == selected.end()){
                    included = false;
                    break;
                }
            }
            if(included)
                return;
        }

        
        set<vector<string>> st;
        
        for (vector<string> &r : relation){
            vector<string> tmp;
            
            for (int col : selected)
                tmp.push_back(r[col]);
            
            st.insert(tmp);
        }
        
        if(st.size() == relation.size())
            ans.push_back(selected);
    }
    
    
    
    
    for (int i = cur; i < relation[0].size(); ++i){
        selected.push_back(i);
        Comb(i+1,relation,len);
        selected.pop_back();
    }
}


int solution(vector<vector<string>> relation) {
    int r = relation.size();
    int c = relation[0].size();
    
    vector<int> selected;
    for (int i = 1; i <= c; ++i){
        Comb(0,relation,i);
    }
    
    
    
    return ans.size();
}