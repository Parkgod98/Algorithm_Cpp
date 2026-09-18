#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int cur_weight = 0;
    int sz = truck_weights.size();
    int t = 1;
    int start = 0;
    
    queue<int> st;
    int idx = 0;
    while(1){
        while(!st.empty() && t-st.front() >= bridge_length){
            cur_weight -= truck_weights[start++];
            st.pop();
        }
        if(idx < sz && (st.size() < bridge_length) && (cur_weight + truck_weights[idx] <= weight)){
            cur_weight += truck_weights[idx++];
            st.push(t);
        }
        // cout << "t : " << t << " st.size() : " << st.size() << "\n";
        ++t;
        
        if(cur_weight == 0)
            break;
    }
    return t-1;
}