#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
 
int main(void) {
    int t, T;
    int a, b;
    scanf("%d", &T);
    for (t = 1; t <= T; t++) {
        printf("#%d ", t);
        scanf("%d %d", &a, &b);
        if (a - b > 0) {
            printf(">\n");
        }
        else if (a - b == 0) {
            printf("=\n");
        }
        else {
            printf("<\n");
        }
    }
    return 0;
}