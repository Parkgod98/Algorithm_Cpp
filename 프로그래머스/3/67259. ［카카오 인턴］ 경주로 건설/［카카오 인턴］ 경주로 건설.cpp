#include <string>
#include <vector>
#include <queue>
#define INF 999999999
using namespace std;

struct Node{
    int y,x;
    int dir;
    int cost;
    
    bool operator<(const Node &other) const{
        return cost > other.cost;
    }
};

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};



int solution(vector<vector<int>> board) {
    int answer = 0;
    
    int sz = board.size();
    
    vector<vector<vector<int>>> dp(sz,vector<vector<int>>(sz,vector<int>(4,INF)));
    
    priority_queue<Node> pq;
    pq.push({0,0,-1,0});
    
    while(!pq.empty()){
        Node cur = pq.top();
        pq.pop();
        
        int y = cur.y;
        int x = cur.x;
        int dir = cur.dir;
        int cost = cur.cost;
        
        if(dir != -1 && cost > dp[y][x][dir])
            continue;
        
        if(y == sz -1 && x == sz -1)
            return cost;
        
        for (int d = 0; d < 4; ++d){
            int ny = y + dy[d];
            int nx = x + dx[d];
            
            if(ny < 0 || ny >= sz || nx < 0 || nx >= sz || board[ny][nx] == 1)
                continue;
            
            int nxt_cost = cost;
            if(dir == -1 || d == dir)
                nxt_cost += 100;
            else
                nxt_cost += 600;
            
            if(nxt_cost < dp[ny][nx][d]){
                dp[ny][nx][d] = nxt_cost;
                pq.push({ny,nx,d,nxt_cost});
            }
        }
    }
    return -1;
}