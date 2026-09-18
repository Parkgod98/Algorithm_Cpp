#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string &a, const string &b){
    
    int i = 0;
    int j = 0;
    while(i < a.size() && j < b.size()){
        if(a[i] != b[i])
            return a[i] > b[i];
        ++i;
        ++j;
    }
    
    string s1 = a + b;
    string s2 = b + a;
    
    return stoi(s1) > stoi(s2);
}

string solution(vector<int> numbers) {
    vector<string> v;
    
    for (int &n : numbers){
        v.push_back(to_string(n));
    }
    
    sort(v.begin(),v.end(),cmp);
    string ans = "";
    
    for (string &s : v)
        ans += s;
    
    if(ans[0] == '0')
        return "0";
    return ans;
}