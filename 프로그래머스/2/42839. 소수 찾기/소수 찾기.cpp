#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ans = 0;

void DFS(vector<char> &v, vector<int> &visited, int n, vector<bool> &IsPrime){
    
    if(IsPrime[n]){
        ++ans;
        IsPrime[n] = false; // 같은 숫자 중복 카운트 방지
    }
    
    for(int i = 0; i < v.size(); ++i){
        if(!visited[i]){
            visited[i] = 1;
            
            int next = n * 10 + v[i] - '0';
            DFS(v, visited, next, IsPrime);
            
            visited[i] = 0;
        }
    }
}

int solution(string numbers) {
    ans = 0;
    
    string tmp = numbers;
    sort(tmp.rbegin(), tmp.rend());
    
    int mx = stoi(tmp);
    
    vector<bool> IsPrime(mx + 1, true);
    
    if(mx >= 0)
        IsPrime[0] = false;
    
    if(mx >= 1)
        IsPrime[1] = false;
    
    for(int i = 2; i * i <= mx; ++i){
        if(!IsPrime[i])
            continue;
        
        for(int j = i * i; j <= mx; j += i){
            IsPrime[j] = false;
        }
    }
    
    vector<char> v;
    for(char &c : numbers)
        v.push_back(c);
    
    vector<int> visited(v.size(), 0);
    
    DFS(v, visited, 0, IsPrime);
    
    return ans;
}