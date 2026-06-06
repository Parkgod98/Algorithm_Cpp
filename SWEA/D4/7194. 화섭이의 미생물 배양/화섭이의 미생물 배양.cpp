#include <stdio.h>
 
int main() {
    int T;
    scanf("%d", &T);
 
    for (int tc = 1; tc <= T; tc++) {
        long long s, t, a, b;
        scanf("%lld %lld %lld %lld", &s, &t, &a, &b);
        long long answer = 0;
        if (b == 1) {
            if ((t - s) % a == 0) {
                answer = (t - s) / a;
            } else {
                answer = -1;
            }
        } else {
            while (t > s) {
                if (t % b == 0 && t / b >= s) {
                    t /= b;
                    answer++;
                } else {
                    t -= a;
                    answer++;
                }
            }
            if (t < s) answer = -1;
        }
 
        printf("#%d %lld\n", tc, answer);
    }
 
    return 0;
}