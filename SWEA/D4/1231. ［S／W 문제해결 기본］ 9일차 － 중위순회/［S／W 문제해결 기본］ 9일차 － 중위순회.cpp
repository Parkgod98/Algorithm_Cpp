#include <cstdio>
#include <cstring>
 
const int T = 10;
int N, ans_idx;
char dat[100];
char answer[101];
 
void inorder(int cnt)
{
    if (cnt > N) return;
    inorder(2 * cnt);
    answer[ans_idx++] = dat[cnt - 1];
    inorder(2 * cnt + 1);
}
 
int main()
{
    int idx, left, right;
    char c;
 
    for (int tc = 1; tc <= T; tc++) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &idx);
            scanf(" %c", &c);
            if (2 * idx <= N)
                scanf("%d", &left);
            if (2 * idx + 1 <= N)
                scanf("%d", &right);
            dat[i] = c;
        }
 
        inorder(1);
        printf("#%d %s\n", tc, answer);
        memset(answer, 0, 100);
        ans_idx = 0;
    }
 
    return 0;
}