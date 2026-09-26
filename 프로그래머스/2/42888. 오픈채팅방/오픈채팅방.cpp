#include <string>
#include <vector>
#include <map>
#include <iostream>
/*

*/

using namespace std;


struct Act{
    int act;
    string uid;
};

vector<string> solution(vector<string> record) {
    map<string,string> id_to_name;
    vector<string> ans;
    
    vector<Act> act;
    
    for (string &s : record){
        int idx = s.find(' ');
        string com = s.substr(0,idx);
        
        int second_space = s.find(' ',idx+1);
        if(second_space == string::npos)
            second_space = s.size();
        
        string uid = s.substr(idx+1, second_space - (idx+1));
        
        if(com == "Enter"){
            string nick = s.substr(second_space+1);
            id_to_name[uid] = nick;
            act.push_back({1,uid});
        }
        else if(com == "Leave"){
            act.push_back({-1,uid});
        }
        else if(com == "Change"){
            string nick = s.substr(second_space+1);              
            id_to_name[uid] = nick;
        }
    }
    
    for (auto &it : act){
        if(it.act == 1){
            string t = id_to_name[it.uid] + "님이 들어왔습니다.";
            ans.push_back(t);
        }
        else if(it.act == -1){
            string t = id_to_name[it.uid] + "님이 나갔습니다.";
            ans.push_back(t);
        }
    }
    
    return ans;
}