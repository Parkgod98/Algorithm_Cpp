#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Node{
    int idx;
    int depth;
};

int solution(string begin, string target, vector<string> words) {
    words.insert(words.begin(),begin);
    
    queue<Node> q;
    vector<int> visited(words.size(),0);
    q.push({0,0});
    visited[0] = 1;
    
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        
        int cur = it.idx;
        int depth = it.depth;
        
        if(words[cur] == target){
            return depth;
        }
        
        for (int i = 1; i < words.size(); ++i){
            if(!visited[i]){
                int diff = 0;
                for (int j = 0; j < begin.size(); ++j){
                    if(words[cur][j] != words[i][j])
                        ++diff;
                }
                if(diff == 1){
                    visited[i] = 1;
                    q.push({i,depth+1});
                }
            }
        }
    }
    return 0;
}