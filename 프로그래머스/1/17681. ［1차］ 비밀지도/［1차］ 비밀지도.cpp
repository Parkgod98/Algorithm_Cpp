#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> ans;
    
    for (int i = 0; i < n; ++i){
        arr1[i] |= arr2[i];
    }

    for (int k : arr1){
        string s = "";
        
        int start = n - 1;
        for (start; start >= 0; --start){
            if((k & (1 << start)) == 0)
                s += " ";
            else
                s += "#";
                
        }
        ans.push_back(s);
    }
    return ans;
}