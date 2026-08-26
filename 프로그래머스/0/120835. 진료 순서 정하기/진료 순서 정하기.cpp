#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> solution(vector<int> emergency) {
    
    int visited[101] = {0};
    for (int &n : emergency){
        visited[n] = 1;
    }
    
    int r = 1;
    
    int rank[101] = {0};
    for (int i = 100; i >= 1; --i){
        if(visited[i])
            rank[i] = r++; 
    }
    
    vector<int> ans;
    for (int &n : emergency)
        ans.push_back(rank[n]);

    return ans;
}