#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

char arr[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    // n진법
    
    
    // t개만큼 구할거고
    
    
    // 게임에는 m명이 참가중
    
    // 튜브의 순서는 p
    
    string ans = "0";
    
    int start = 1;
    while(1){
        int now = start;
        string tmp = "";
        while(now != 0){
            tmp += arr[now%n];
            now /= n;
        }
        reverse(tmp.begin(),tmp.end());
        ans += tmp;
        ++start;
        
        if(ans.size()/m >= t){
            break;
        }
    }
    
    string rans = "";
    for (int i = p-1; i < ans.size(); i += m){
        rans += ans[i];
        if(rans.size() == t)
            break;
    }
    
    cout << rans << "\n";
    return rans;
}