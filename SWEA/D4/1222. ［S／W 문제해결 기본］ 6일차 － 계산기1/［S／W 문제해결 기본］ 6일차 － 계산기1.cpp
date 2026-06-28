#include <stdio.h>
int iLen, iRes;
char stack[250];
int main(void){
    for (int i = 1; i < 11; i++){
        iRes = 0;
        scanf("%d", &iLen);
        scanf("%s", stack);
        for (int j = 0; j < iLen; j+=2)
            iRes += stack[j]-'0';
        printf("#%d %d\n", i, iRes);
    }
    return 0;
}