#include <string>
#include <vector>
#include <iostream>
using namespace std;

void PrintV(vector<int> v){
    for (int i : v)
        cout << i << " ";
    cout << "\n";
}

vector<int> solution(vector<int> arr) {
    vector<int> stk;
    
    int i = 0;
    while(i < arr.size()){
        if(stk.size() == 0)
            stk.push_back(arr[i++]);
        else {
            if(stk[stk.size()-1] < arr[i])
                stk.push_back(arr[i++]);
            else
                stk.pop_back();
        }
        
    }
    return stk;
}