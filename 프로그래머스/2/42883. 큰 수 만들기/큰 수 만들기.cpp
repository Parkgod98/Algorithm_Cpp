#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
    
    stack<char> st;
    int sz = number.size();
    int cnt = 0;
    for (int i = 0; i < sz; ++i){
        if(!st.empty()){
            while(!st.empty() && cnt < k && st.top() < number[i]){
                st.pop();
                ++cnt;
            }
        }
        st.push(number[i]);
    }
    
    while(cnt < k){
        st.pop();
        ++cnt;
    }
    
    string ans = "";
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}