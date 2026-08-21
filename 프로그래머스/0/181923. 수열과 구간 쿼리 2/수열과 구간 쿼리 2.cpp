#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> ans;
    
    for(vector<int> &v : queries){
        int s = v[0];
        int e = v[1];
        int k = v[2];
        
        int mn = 9999999;
        for (s; s <= e; ++s){
            if(arr[s] > k && mn > arr[s]){
                mn = arr[s];
            }
        }
        if(mn == 9999999)
            ans.push_back(-1);
        else
            ans.push_back(mn);
    }
    return ans;
}