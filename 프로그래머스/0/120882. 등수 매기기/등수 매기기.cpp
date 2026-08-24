#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Point{
    int sum;
    int idx;
    
    bool operator<(const Point &other) const {
        return sum > other.sum;
    }
};

vector<int> solution(vector<vector<int>> score) {
    vector<int> rank(score.size());
    vector<Point> v;
    
    int sz = score.size();
    for (int i = 0; i < sz; ++i){
        v.push_back({score[i][0] + score[i][1],i});
    }
    sort(v.begin(),v.end());
    
    int prev = -1;
    for (int i = 0; i < v.size(); ++i){
        if(v[i].sum == prev){
            rank[v[i].idx] = rank[v[i-1].idx];
        }
        else{
           rank[v[i].idx] = i+1; 
        }
        prev = v[i].sum;
    }
    return rank;
}