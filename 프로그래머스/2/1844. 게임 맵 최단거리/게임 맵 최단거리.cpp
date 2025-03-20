#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cctype>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <cmath>
#include <unordered_map>
#include <stack>
#include <deque>
#include <list>
using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int solution( vector<vector<int> > maps )
{
    int cnt = 0;

    queue<pair<int, int>> q;
    vector<vector<int>> visited( maps.size(), vector<int>( maps[0].size(), 0 ) );
    q.push( { 0,0 } );
    visited[0][0] = 1;
    while( !q.empty() )
    {
        auto p = q.front();
        q.pop();
        for( int i = 0; i < 4; ++i )
        {
            int ny = p.first + dy[i];
            int nx = p.second + dx[i];
            if( ny < 0 || nx < 0 || ny >= maps.size() || nx >= maps[0].size() || visited[ny][nx] || maps[ny][nx] == 0 )
                continue;
            q.push( { ny,nx } );
            visited[ny][nx] = visited[p.first][p.second] + 1;
        }
    }
    if( visited[maps.size() - 1][maps[0].size() - 1] == 0 )
        return -1;
    else
        return visited[maps.size() - 1][maps[0].size() - 1];
}