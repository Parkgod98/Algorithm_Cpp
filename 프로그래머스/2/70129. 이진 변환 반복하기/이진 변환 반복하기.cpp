#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> ans(2);

    int ezin = 0;
    int zero_cnt = 0;
    while (s != "1") {

        int sz = s.size();
        int cnt = 0;
        for (char& c : s) {
            if (c == '1') {
                ++cnt;
            }
        }
        zero_cnt += (sz - cnt);

        int n_sz = cnt;
        string nn = "";

        while (n_sz != 0) {
            nn += (n_sz % 2 + '0');
            n_sz /= 2;
        }
        reverse(nn.begin(), nn.end());
        s = nn;
        ++ezin;
    }

    ans[0] = ezin;
    ans[1] = zero_cnt;
    return ans;
}