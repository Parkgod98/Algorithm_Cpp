#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> ans;
    
    for (vector<int> &v : commands){
        int i = v[0] - 1;
        int j = v[1] - 1;
        
        vector<int> vv;
        for (int ii = i ; ii <= j; ++ii)
            vv.push_back(array[ii]);
        sort(vv.begin(),vv.end());
        
        int k = v[2];
        ans.push_back(vv[k-1]);
    }
    return ans;
}