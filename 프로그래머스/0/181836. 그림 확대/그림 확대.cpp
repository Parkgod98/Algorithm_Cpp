#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> picture, int k) {
    int sz = picture.size();
    vector<string> ans(sz*k);
    
    int ii = 0;
    for (string &s : picture){
        
        string n = "";
        int n_sz = s.size();
        for (int i = 0; i < n_sz; ++i){
            for (int j = 0; j < k; ++j)
                n += s[i];
        }
        for (int j = 0; j < k; ++j)
            ans[ii++] = n;
    }
    return ans;
}