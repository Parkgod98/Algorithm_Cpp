#include <string>
#include <vector>
#include <stack>

using namespace std;

struct Point{
    int value;
    int t;
};

vector<int> solution(vector<int> prices) {
    int sz = prices.size();
    vector<int> ans(sz,0);
    
    stack<Point> st;
    
    for (int i = sz - 1; i >= 0; --i){
        
        while(!st.empty() && prices[i] <= st.top().value){
            st.pop();
        }
        
        if(!st.empty()){
            ans[i] = st.top().t - i;
        }
        else
            ans[i] = sz - i - 1;

        st.push({prices[i],i});
    }
    return ans;
}