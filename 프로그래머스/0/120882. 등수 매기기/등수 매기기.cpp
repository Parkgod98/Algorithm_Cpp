#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Point{
    int sum;
    int idx;
    
    bool operator<(const Point &other) const {
        if(sum != other.sum)
            return sum > other.sum;
        return idx < other.idx;
    }
};

vector<int> solution(vector<vector<int>> score) {
    vector<int> rank(score.size());
    vector<Point> v;
    
    int sz = score.size();
    for (int i = 0; i < sz; ++i){
        v.push_back({score[i][0] + score[i][1],i});
    }
    
    int cur = 1;
    sort(v.begin(),v.end());
    
    int prev = -1;
    for (int i = 0; i < v.size(); ++i){
        if(v[i].sum == prev){
            rank[v[i].idx] = rank[v[i-1].idx];
        }
        else{
           rank[v[i].idx] = cur; 
        }
        ++cur;
        prev = v[i].sum;
    }
    return rank;
}