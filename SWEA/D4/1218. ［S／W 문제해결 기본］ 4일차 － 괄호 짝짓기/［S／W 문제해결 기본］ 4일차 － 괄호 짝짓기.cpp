#include<iostream>
#include<stack>
#include<map>
 
using namespace std;
 
int main(int argc, char** argv)
{
    int test_case;
    int T=10;
    map<char, char> dic;
    dic.insert({'(', ')'});
    dic.insert({'[', ']'});
    dic.insert({'{', '}'});
    dic.insert({'<', '>'});
 
    for(test_case = 1; test_case <= T; ++test_case)
    {
        stack<char> st;
         
        int l;
        string input;
        cin >> l >> input;
        int flag=1;
         
        for(char c : input){
            if(c=='{' || c == '[' || c=='(' || c=='<'){
                st.push(c);
            }else{
                char exp = dic[st.top()];
                st.pop();
                 
                if(exp!=c){
                    flag=0;
                    break;
                }
            };
        }
        cout << "#" << test_case << " " << flag << "\n";
    }
    return 0;
}