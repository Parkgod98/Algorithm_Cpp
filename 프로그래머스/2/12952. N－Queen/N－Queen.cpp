#include <vector>
#include <cmath>

using namespace std;

int cnt = 0;

void DFS(int n, int r, vector<int>& queen) {
    if (r == n) {
        ++cnt;
        return;
    }

    for (int c = 0; c < n; ++c) {
        bool valid = true;

        for (int prev = 0; prev < r; ++prev) {
            if (queen[prev] == c ||
                abs(r - prev) == abs(c - queen[prev])) {
                valid = false;
                break;
            }
        }

        if (!valid)
            continue;

        queen[r] = c;
        DFS(n, r + 1, queen);
    }
}

int solution(int n) {
    cnt = 0;

    vector<int> queen(n, -1);
    DFS(n, 0, queen);

    return cnt;
}