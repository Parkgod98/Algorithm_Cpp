#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> numbers) {
    
    int mx1 = -20000;
    int mx2 = -19999;
    int mn1 = 20000;
    int mn2 = 20001;
    
    for (int &n : numbers){
        if(n > mx1){ 
            mx2 = mx1;
            mx1 = n;
        }
        else if(mx1 >= n && mx2 <= n){
            mx2 = n;
        }
        
        if(n < mn1){
            mn2 = mn1;
            mn1 = n;
        }
        else if(mn1 <= n && mn2 >= n){
            mn2 = n;
        }
    }
    
    return mx1*mx2 > mn1*mn2 ? mx1*mx2 : mn1*mn2;
}