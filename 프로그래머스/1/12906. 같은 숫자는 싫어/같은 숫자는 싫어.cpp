#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> ans;
    
    int prev = -1;
    for (int &n : arr){
        if(n != prev)
            ans.push_back(n);
        prev = n;
    }

    return ans;
}