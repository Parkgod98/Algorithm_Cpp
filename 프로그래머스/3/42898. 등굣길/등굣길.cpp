#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define MOD 1000000007

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    int arr[103][103] = {0};
    
    arr[0][0] = 1;
    for (vector<int> &v : puddles){
        arr[v[1]-1][v[0]-1] = -10;
    }
    
    
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if(arr[i][j] == -10)
                continue;
            
            if(i-1 >= 0 && j-1 >= 0){
                if(arr[i-1][j] != -10)
                    arr[i][j] += arr[i-1][j];
                if(arr[i][j-1] != -10)
                    arr[i][j] += arr[i][j-1];
            }
            else if(i == 0 && j != 0){
                if(arr[i][j-1] != -10)
                    arr[i][j] = arr[i][j-1];   
            }
            else if(j == 0 && i != 0){
                if(arr[i-1][j] != -10)
                    arr[i][j] = arr[i-1][j];
            }
            arr[i][j] %= MOD;
        }
    }
    
    return arr[n-1][m-1];
}