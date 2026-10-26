#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> selected;
vector<vector<int>> ans;

void Comb(int cur, vector<vector<string>> &relation, int len){
    
    if(selected.size() == len){
        for (vector<int> &key : ans){
            bool included = true;
            
            for (int &col : key){
                if(find(selected.begin(),selected.end(),col) == selected.end()){
                    included = false;
                    break;
                }
            }
            
            if(included)
                return;
        }
        
        set<vector<string>> st;
        
        for (int i = 0; i < relation.size(); ++i){
            vector<string> tmp;
            for (int &s : selected){
                tmp.push_back(relation[i][s]);
            }
            st.insert(tmp);
        }
        
        if(st.size() == relation.size())
            ans.push_back(selected);
        
        return;
    }
    
    for (int i = cur; i < relation[0].size(); ++i){
        selected.push_back(i);
        Comb(i+1,relation,len);
        selected.pop_back();
    }
        
}


int solution(vector<vector<string>> relation) {
    
    for (int i = 1; i <= relation[0].size(); ++i){
        Comb(0,relation,i);
    }
    return ans.size();
}