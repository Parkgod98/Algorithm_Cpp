#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int solution(string s) {
    int so,sc,mo,mc,bo,bc;
    so = sc = mo = mc = bo = bc = 0;
    int sz = s.size();
    
    deque<char> dq;
    for (char &c : s){
        if(c == '(')
            ++so;
        else if(c == ')')
            ++sc;
        else if(c == '{')
            ++mo;
        else if(c == '}')
            ++mc;
        else if(c == '[')
            ++bo;
        else if(c == ']')
            ++bc;
        dq.push_back(c);
    }
    if(so != sc || mo != mc || bo != bc)
        return 0;
    
    
    int ans = 0;
    for (int i = 0; i < sz; ++i){
        stack<char> st;
        
        for (char &c : dq){
            if(!st.empty()){
                if(st.top() == '(' && c == ')')
                    st.pop();
                else if(st.top() == '[' && c == ']')
                    st.pop();
                else if(st.top() == '{' && c == '}')
                    st.pop();
                else
                    st.push(c);
            }
            else
                st.push(c);
        }
        if(st.empty())
            ++ans;
        dq.push_back(dq.front());
        dq.pop_front();
    }
    return ans;
}