#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> dots) {
    vector<pair<int,int>> v1 = { {0,1},{0,2},{0,3} };
    vector<pair<int,int>> v2 = { {2,3},{1,3},{1,2} };

    for (int i = 0; i < 3; ++i) {
        double l1 = (double)(dots[v1[i].first][1]- dots[v1[i].second][1]) /(dots[v1[i].first][0] - dots[v1[i].second][0]);
        double l2 = (double)(dots[v2[i].first][1] - dots[v2[i].second][1]) / (dots[v2[i].first][0] - dots[v2[i].second][0]);
        if (l1 == l2) {
            return 1;
        }
    }
    return 0;
}