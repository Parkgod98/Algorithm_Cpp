#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    queue<int> q;
    q.push(5);
    
    while(!q.empty()){
        int num = q.front();
        q.pop();
        
        if(num >= l && num <= r)
            answer.push_back(num);
        else if(num > r)
            break;
        
        q.push(num*10);
        q.push(num*10+5);
    }
    
    if(answer.size() == 0)
        return vector<int>(1,-1);
    return answer;

}