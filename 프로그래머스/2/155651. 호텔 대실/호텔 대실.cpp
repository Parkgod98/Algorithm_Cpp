#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct SE{
    int st;
    int et;
    
    bool operator<(const SE &other) const{
        if(et != other.et)
            return et < other.et;
    }
};

int solution(vector<vector<string>> book_time) {
    int sz = book_time.size();
    vector<SE> v(sz);
    
    for (int i = 0; i < sz; ++i){
        string &s = book_time[i][0];
        string &e = book_time[i][1];
        
        int idx = s.find(':');
        int st = stoi(s.substr(0,idx))*60 + stoi(s.substr(idx+1));
        idx = e.find(':');
        int et = stoi(e.substr(0,idx))*60 + stoi(e.substr(idx+1)) + 10;
        v[i] = {st,et};
    }
    
    int arr[1500] = {0};
    for (int i = 0; i < sz; ++i){
        cout << v[i].st << " " << v[i].et << "\n";
        for (int j = v[i].st; j < v[i].et; ++j)
            arr[j]++;
    }
    
    int mx = 0;
    for (int i = 0; i < 1450; ++i)
        mx = max(arr[i],mx);
    return mx;
}