#include <string>
#include <vector>
#include <cctype>
using namespace std;

string solution(string new_id) {
    string answer = "";
    
    for (char &c : new_id){
        c = tolower(c);
    }
    string ans = "";
    for (char &c : new_id){
        if(isalpha(c)){
            ans += c;
        }
        else if(isdigit(c))
            ans += c;
        else if((c == '-' || c == '_' || c == '.')){
            ans +=c;
        }
    }
    
    int sz = ans.size();
    string new_ans = "";
    for (int i = 0; i < sz; ++i){
        if(ans[i] != '.')
            new_ans += ans[i];
        else{
            while(ans[i] == '.')
                i++;
            new_ans += '.';
            --i;
        }
    }
    
    if(new_ans[0] == '.')
        new_ans = new_ans.substr(1);
    if(new_ans[new_ans.size()-1] == '.')
        new_ans.pop_back();
    
    if(new_ans.size() == 0)
        new_ans +="a";
    else if(new_ans.size() >= 16){
        new_ans = new_ans.substr(0,15);
        if(new_ans[new_ans.size()-1] == '.')
            new_ans.pop_back();
    }
    
    while(new_ans.size() <= 2){
        new_ans.push_back(new_ans[new_ans.size()-1]);
    }
    return new_ans;
}