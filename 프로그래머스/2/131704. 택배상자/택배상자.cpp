#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int ans = 0;
    int sz = order.size();
    
    stack<int> st;
    int idx = 0;
    for (int i = 1; i <= sz; ++i){
        while(!st.empty() && st.top() == order[idx]){
            st.pop();
            ++idx;
            ++ans;
        }
        if(i == order[idx]){
            ++idx;
            ++ans;
        }
        else{
            st.push(i);
        }
    }
    
    while(!st.empty()){
        if(idx < sz && st.top() == order[idx]){
            ++idx;
            ++ans;
            st.pop();
        }
        else
            break;
    }
    
    return ans;
}