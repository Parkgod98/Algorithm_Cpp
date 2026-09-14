#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    set<string> st;
    vector<int> ans(2,0);
    vector<int> die(n,0);
    vector<int> alive(n,0);
    
    int sz = words.size();
    
    int turn = 0;
    char prev = words[0][0];
    for (int i = 0; i < sz; ++i){
        alive[turn]++;
        if(st.find(words[i]) != st.end() || prev != words[i][0]){
            if(ans[0] == 0){
                ans[0] = turn+1;
                ans[1] = alive[turn];
            }
            die[turn] = true;
        }
        else{
            st.insert(words[i]);
        }
        ++turn;
        turn%=n;
        while(die[turn])
            ++turn;
        prev = words[i][words[i].size()-1];
    }
    return ans;
}