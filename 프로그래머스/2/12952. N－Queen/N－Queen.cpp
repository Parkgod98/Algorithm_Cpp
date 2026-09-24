#include <vector>

using namespace std;

int cnt = 0;

void DFS(int n, int r,
         vector<int>& col,
         vector<int>& diag1,
         vector<int>& diag2) {

    if (r == n) {
        ++cnt;
        return;
    }

    for (int c = 0; c < n; ++c) {

        int d1 = r - c + n - 1;
        int d2 = r + c;

        if (col[c] || diag1[d1] || diag2[d2])
            continue;

        col[c] = 1;
        diag1[d1] = 1;
        diag2[d2] = 1;

        DFS(n, r + 1, col, diag1, diag2);

        col[c] = 0;
        diag1[d1] = 0;
        diag2[d2] = 0;
    }
}

int solution(int n) {
    cnt = 0;

    vector<int> col(n, 0);
    vector<int> diag1(2 * n - 1, 0);
    vector<int> diag2(2 * n - 1, 0);

    DFS(n, 0, col, diag1, diag2);

    return cnt;
}