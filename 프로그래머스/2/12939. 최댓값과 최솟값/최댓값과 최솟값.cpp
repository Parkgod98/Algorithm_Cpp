#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    stringstream ss(s);
    
    string word;
    
    vector<int> v;
    while(ss >> word){
        v.push_back(stoi(word));
    }
    
    sort(v.begin(),v.end());
    
    string ans = "";
    
    ans += to_string(v[0]) + " " + to_string(v[v.size()-1]);
    return ans;
}