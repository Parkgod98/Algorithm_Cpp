#include <string>
#include <vector>
#include <deque>

using namespace std;

string solution(vector<int> food) {
    
    deque<char> dq;
    dq.push_back('0');
    
    int sz = food.size();
    for (int i = sz-1; i >= 1; --i){
        
        int it = (food[i]/2)*2;
        for (int k = 1; k <= it/2; ++k){
            dq.push_front(i+'0');
            dq.push_back(i+'0');
        }
    }
    
    string ans = "";
    while(!dq.empty()){
        ans += dq.front();
        dq.pop_front();
    }
    return ans;
}