#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> files) {
    vector<string> head;
    vector<int> num;

    for(string &s : files){
        int idx = 0;

        while(idx < s.size() && !isdigit(s[idx]))
            ++idx;

        string hp = s.substr(0,idx);

        for(char &c : hp)
            c = tolower(c);

        head.push_back(hp);

        int st = idx;

        while(idx < s.size() && isdigit(s[idx]) && idx-st < 5)
            ++idx;

        num.push_back(stoi(s.substr(st,idx-st)));
    }

    vector<int> idx(files.size());

    for(int i=0;i<files.size();++i)
        idx[i] = i;

    sort(idx.begin(),idx.end(),[&](int a,int b){
        if(head[a] != head[b])
            return head[a] < head[b];

        if(num[a] != num[b])
            return num[a] < num[b];

        return a < b;
    });

    vector<string> ans;

    for(int i : idx)
        ans.push_back(files[i]);

    return ans;
}