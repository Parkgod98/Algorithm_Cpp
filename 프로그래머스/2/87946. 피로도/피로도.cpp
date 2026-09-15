#include <string>
#include <vector>

using namespace std;

int mx = 0;
int visited[10] = { 0 };
int cnt = 0;
int sz;
void DFS(int hp, vector<vector<int>>& d) {
    mx = max(cnt, mx);

    for (int i = 0; i < sz; ++i) {
        if (!visited[i]) {
            if (hp >= d[i][0]) {
                visited[i] = 1;
                ++cnt;
                DFS(hp - d[i][1], d);
                visited[i] = 0;
                --cnt;
            }
        }
    }

}

int solution(int k, vector<vector<int>> dungeons) {
    sz = dungeons.size();

    for (int i = 0; i < sz; ++i) {
        if (!visited[i] && k >= dungeons[i][0]) {
            visited[i] = 1;
            ++cnt;
            DFS(k - dungeons[i][1], dungeons);
            visited[i] = 0;
            --cnt;
        }
    }


    return mx;
}