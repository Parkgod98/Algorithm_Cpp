#include<stdio.h>
int N,M;
long long max;
int arr[100];
 
void input_data(){
    scanf("%d %d", &N, &M);
    max = 1;
    int i;
    for (i = 0; i < 100; i++) arr[i] = 0;
}
 
long long solve(){
    long long ret = 0;
    int i;
    int cur = 0;
    for (i = 0; i < N; i++){
        arr[cur]++;
        cur++;
        cur = cur % M;
    }
 
    for (i = 0; i < M; i++){
        max *= arr[i];
    }
 
    return ret;
}
 
int main(){
    int T;
    scanf("%d", &T);
    int i;
    for (i = 1; i <= T; i++){
        input_data();
        long long ans = solve();
        printf("#%d %lld\n", i, max);
    }
    return 0;
}