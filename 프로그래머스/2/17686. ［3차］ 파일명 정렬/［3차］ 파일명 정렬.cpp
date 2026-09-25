#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


struct File{
    string origin;
    string head;
    int num;
    int order;
    
    
    bool operator<(const File &other) const{
        if(head != other.head)
            return head < other.head;
        if(num != other.num)
            return num < other.num;
        return order < other.order;
    }
};



vector<string> solution(vector<string> files) { 
    vector<string> ans;
    
    vector<string> head;
    vector<int> num;
    
    vector<File> v;
    int o = 0;
    for (string &s : files){
        int idx = 0;
        while(idx < s.size() && !isdigit(s[idx]))
            ++idx;
        
        File f;
        f.origin = s;
        f.order = o++;
        string hp = s.substr(0,idx);
        for (char &c : hp)
            c = tolower(c);
        f.head = hp;
        int st = idx;
        while(idx < s.size() && isdigit(s[idx]) && idx - st < 5)
            ++idx;
        f.num = stoi(s.substr(st,idx-st));
        v.push_back(f);
    }
    sort(v.begin(),v.end());
    
    for (auto &it : v)
        ans.push_back(it.origin);
    
    return ans;
}