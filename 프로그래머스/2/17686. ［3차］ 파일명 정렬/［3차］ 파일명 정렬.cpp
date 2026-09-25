#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> files) { 
    vector<string> ans;
    
    vector<string> head;
    vector<int> num;
    
    for (string &s : files){
        
        int idx = 0;
        while(idx < s.size() && !isdigit(s[idx]))
            ++idx;
        
        string hp = s.substr(0,idx);
        for (char &c : hp)
            c = tolower(c);
        head.push_back(hp);
        int st = idx;
        while(idx < s.size() && isdigit(s[idx]) && idx - st < 5)
            ++idx;
        
        num.push_back(stoi(s.substr(st,idx-st)));
    }
    
    int sz = files.size();
    for (int i = 0; i < sz - 1; ++i){
        for (int j = 0; j < sz - i - 1; ++j){
            if(head[j] > head[j+1]){
                swap(head[j],head[j+1]);
                swap(files[j],files[j+1]);
                swap(num[j],num[j+1]);
            }
            else if(head[j] == head[j+1]){
                if(num[j] > num[j+1]){
                    swap(head[j],head[j+1]);
                    swap(files[j],files[j+1]);
                    swap(num[j],num[j+1]);
                }
            }
        }
    }
    
    return files;
}