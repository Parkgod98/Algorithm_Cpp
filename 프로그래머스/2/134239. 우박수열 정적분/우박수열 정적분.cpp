#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Point{
    int x,y;
};

vector<double> solution(int k, vector<vector<int>> ranges) {
    
    vector<Point> v;
    v.push_back({0,k});
    int x = 1;
    while(k != 1){
        if(k%2 == 0){
            k/=2;
        }
        else{
            k = k*3 + 1;
        }
        v.push_back({x,k});
        ++x;
    }
    
    int n = x-1;
    vector<double> ans;
    
    for (vector<int> &r : ranges){
        int start = r[0];
        int end = n+r[1];
        if(end > n || start > end){
            ans.push_back(-1);
        }
        else{
            double sum = 0;
            for (int i = start; i < end; ++i){
                int h1 = v[i].y;
                int h2 = v[i+1].y;
                sum += (h1 + h2)/2.0;
            }
            ans.push_back(sum);
        }
    }

    return ans;
}