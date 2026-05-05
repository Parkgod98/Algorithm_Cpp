#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
 
using namespace std;
 
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
 
struct coor
{
    int x;
    int y;
};
 
coor des;
int map[16][16] = { 0 };
bool visited[16][16] = { false };
 
bool bfs(coor st)
{
    queue<pair<int,int>>q;
    q.push({ st.y, st.x });
    while (!q.empty())
    {
        coor now;
        now.y = q.front().first;
        now.x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (map[ny][nx] != 1 && visited[ny][nx] == false)
            {
                if (map[ny][nx] == 3)
                {
                    return true;
                }
                visited[ny][nx] = true;
                q.push({ ny,nx });
            }
        }
    }
    return false;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int test_case;
    while (cin >> test_case)
    {
        memset(visited, false, sizeof(visited));
        memset(map, 0, sizeof(map));
        coor st = {0,0};
        for (int i = 0; i < 16; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < 16; j++)
            {
                map[i][j] = s[j]-'0';
                if (map[i][j] == 2)
                {
                    st.y = i;
                    st.x = j;
                }
                if (map[i][j] == 3)
                {
                    des.y = i;
                    des.x = j;
                }
            }
        }
 
        visited[st.y][st.x] = true;
        if (bfs(st))
        {
            cout << '#' << test_case << " " << 1<<"\n";
        }
        else
        {
            cout << '#' << test_case << " " << 0<<"\n";
        }
    }
    return 0;
}