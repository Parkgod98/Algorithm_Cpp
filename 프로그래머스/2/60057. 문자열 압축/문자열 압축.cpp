#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string s) {
    int ans = 99999999;
    int sz = s.size();
    for (int i = 1; i <= sz; ++i){
        int cnt = 1;
        string t = "";
        string prev = "";
        string cur = "";
        for (int j = 0; j < sz; j+=i){
            cur = s.substr(j,i);
            if(prev == cur){
                ++cnt;
                prev = cur;
            }
            else{
                // cout << cnt << " " << prev << "\n";
                if(cnt != 1)
                    t += to_string(cnt);
                t += prev;
                cnt = 1;
                prev = cur;
                // cout << t << "\n\n";
            }
        }
        if(cnt != 1){
            t += to_string(cnt);
            t += prev;
        }
        else{
            t += cur;
        }
        // cout << t << "\n\n";
        
        ans = min(ans,(int)t.size());
    }
    return ans;
}