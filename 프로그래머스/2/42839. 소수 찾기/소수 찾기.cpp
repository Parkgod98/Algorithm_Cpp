#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ans = 0;

void DFS(vector<char> &v, vector<int> &visited, string &s, vector<bool> &chk){
    
    if(s.size() > 0){
        int n = stoi(s);
        if(chk[n]){
            ++ans;
            chk[n] = false;
        }
    }
    
    for (int i = 0; i < v.size(); ++i){
        if(!visited[i]){
            visited[i] = 1;
            s += v[i];
            DFS(v,visited,s,chk);
            s.pop_back();
            visited[i] = 0;
        }
    }
}

int solution(string numbers) {
    vector<bool> IsPrime(10000001,true);
    IsPrime[0] = IsPrime[1] = false;
    
    for (int i = 2; i * i <= 10000000; ++i){
        if(!IsPrime[i])
            continue;
        for (int j = i * i; j <= 10000000; j+=i){
            IsPrime[j] = false;
        }
    }
    
    vector<char> v;
    for (char &c : numbers)
        v.push_back(c);
    sort(v.begin(),v.end());
    
    vector<int> visited(v.size(),0);
    string s = "";
    DFS(v,visited,s, IsPrime);
    
    
    return ans;
}