#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> lines) {
    vector<int> v(201,0);
    for (vector<int> &vv : lines){
        for (int i = vv[0]+100; i < vv[1]+100; ++i)
            v[i]++;
    }
    int cnt = 0;
    for (int i : v)
        if(i>=2)
            cnt++;
    return cnt;
}