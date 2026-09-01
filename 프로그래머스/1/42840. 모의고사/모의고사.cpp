#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int sz = answers.size();
    int arr[5] = {1,2,3,4,5};
    int arr2[8] = {2,1,2,3,2,4,2,5};
    int arr3[10] = {3,3,1,1,2,2,4,4,5,5};
    
    int a,b,c;
    a = b = c = 0;
    int a1,a2,a3;
    a1 = a2 = a3 = 0;
    for (int i = 0; i < sz; ++i){
        if(answers[i] == arr[a1++])
            a++;
        if(answers[i] == arr2[a2++])
            b++;
        if(answers[i] == arr3[a3++])
            c++;
        
        a1%=5;
        a2%=8;
        a3%=10;
    }
    
    vector<int> ans;
    int k = max(a,max(b,c));
    if(k == a)
        ans.push_back(1);
    if(k == b)
        ans.push_back(2);
    if(k == c)
        ans.push_back(3);
    return ans;
}