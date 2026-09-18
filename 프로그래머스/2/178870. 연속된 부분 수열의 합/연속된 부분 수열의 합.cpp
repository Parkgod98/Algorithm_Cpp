#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int mn = 10000000;
    int ss,ee;
    ss = ee = 1000000;
    int s = 0;
    int e = 1;
    int sum = sequence[s];
    int sz = sequence.size();
    while(s < sz && e <= sz){
        // cout << "s : " << s << " e : " << e << " sum : " << sum << "\n";
        if(sum == k){
            int cur_len = e - s;
            if(cur_len < mn){
                mn = cur_len;
                ss = s;
                ee = e;
            }
            else if(cur_len == mn && s < ss){
                ss = s;
                ee = e;
            }
            sum -= sequence[s];
            ++s;
        }
        else if(sum > k){
            sum -= sequence[s];
            ++s;
        }
        else{ // sum < k
            if(e >= sz)
                break;
            sum += sequence[e];
            ++e;
        }
    }
    
    vector<int> ans(2,0);
    ans[0] = ss;
    ans[1] = ee-1;
    return ans;
}