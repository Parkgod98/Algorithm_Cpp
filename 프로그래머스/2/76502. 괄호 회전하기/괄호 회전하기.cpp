#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int so,sc,mo,mc,bo,bc;
    so = sc = mo = mc = bo = bc = 0;
    int sz = s.size();
    
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
    }
    if(so != sc || mo != mc || bo != bc)
        return 0;
    
    
    int ans = 0;
    for (int i = 0; i < sz; ++i){
        stack<char> st;
        
        bool valid = true;
        for (int j = 0; j < sz; ++j){
            char c = s[(i+j)%sz];
            
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            }
            else{
                if(st.empty()){
                    valid = false;
                    break;
                }
                if((st.top() == '(' && c != ')') ||
                   (st.top() == '[' && c != ']') ||
                   (st.top() == '{' && c != '}')){
                    valid = false;
                    break;
                }
                else{
                    st.pop();
                }
            }
        }
        if(valid &&st.empty())
            ++ans;
    }
    
    return ans;
}