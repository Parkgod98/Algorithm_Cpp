#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(vector<int> weights) {
    long long ans = 0;
    int arr[1002] = {0};
    for (int &n : weights){
        arr[n]++;
    }
    
    
    for (int i = 1; i <= 1000; ++i){
        if(!arr[i])
            continue;
        ans += ((long long)arr[i]*(arr[i]-1))/2;
        if(i%2 == 0 && i*1.5 <= 1000){
            // cout << i << "\n";
            // cout << i *1.5 << "\n";
            int k = i*1.5;
            ans += ((long long)arr[i]*arr[k]);
        }
        if(i*2 <= 1000){
            ans += (long long)arr[i] * arr[i*2];
        }
        if(i%3 == 0 && i * (4.0/3) <= 1000){
            int k = i*(4.0/3);
            ans += (long long)arr[i]*arr[k];
        }
    }
    return ans;
}