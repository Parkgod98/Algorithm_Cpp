#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<vector<string>> relation) {
    int rows = relation.size();
    int cols = relation[0].size();
    
    vector<int> keys;
    for (int mask = 1; mask < (1 << cols); ++mask){
        
        bool minimal = true;
        
        for (int key : keys){
            if((mask&key) == key){
                minimal = false;
                break;
            }
        }
        if(!minimal)
            continue;
        
        set<vector<string>> st;
        
        for (int i = 0; i < rows; ++i){
            vector<string> tmp;
            
            for (int j = 0; j < cols; ++j){
                if(mask & (1 << j)){
                    tmp.push_back(relation[i][j]);
                }
            }
            st.insert(tmp);
        }
        
        if(st.size() == rows)
            keys.push_back(mask);
        
    }
    return keys.size();
}