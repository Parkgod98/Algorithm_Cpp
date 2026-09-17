#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    int sz = numbers.size();
    vector<int> ans(sz,0);
    
    stack<int> st;
    
    for (int i = sz - 1; i >= 0; --i){
        while(!st.empty() && numbers[i] >= st.top()){
            st.pop();
        }
        if(!st.empty())
            ans[i] = st.top();
        else{
            ans[i] = -1;
        }
        st.push(numbers[i]);
    }
    return ans;
}