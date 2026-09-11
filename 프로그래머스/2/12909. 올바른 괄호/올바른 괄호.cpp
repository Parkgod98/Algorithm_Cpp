#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> st;
    for (char &c : s){
        if(!st.empty()){
            if(st.top() == '(' && c  == ')')
                st.pop();
            else
                st.push(c);
        }        
        else
            st.push(c);
    }
    if(!st.empty())
        return false;
    return true;

}