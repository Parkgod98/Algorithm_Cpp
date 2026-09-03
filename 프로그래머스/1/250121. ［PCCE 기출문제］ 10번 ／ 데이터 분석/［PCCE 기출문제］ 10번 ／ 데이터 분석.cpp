#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> ans;
    
    int mode = 0;
    if(ext == "code"){
        mode = 1;
    }
    else if(ext == "date"){
        mode = 2;
    }
    else if(ext == "maximum"){
        mode = 3;
    }
    else if(ext == "remain"){
        mode = 4;
    }
    for(vector<int> &v : data){
        if(mode == 1){
            if(v[0] < val_ext)
                ans.push_back(v);
        }
        else if(mode == 2){
            if(v[1] < val_ext)
                ans.push_back(v);
        }
        else if(mode == 3){
            if(v[2] < val_ext)
                ans.push_back(v);
        }
        else if(mode == 4){
            if(v[3] < val_ext)
                ans.push_back(v);
        }
    }
    
    if(sort_by == "code"){
        sort(ans.begin(),ans.end(),[](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });
    }
    else if(sort_by == "date"){
        sort(ans.begin(),ans.end(),[](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });
    }
    else if(sort_by == "maximum"){
        sort(ans.begin(),ans.end(),[](vector<int> &a, vector<int> &b){
            return a[2] < b[2];
        });
    }
    else if(sort_by == "remain"){
        sort(ans.begin(),ans.end(),[](vector<int> &a, vector<int> &b){
            return a[3] < b[3];
        });
    }
    return ans;
}