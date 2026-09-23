#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    
    sort(data.begin(),data.end(),[&](vector<int> &a, vector<int> &b){
        if(a[col-1] != b[col-1])
            return a[col-1] < b[col-1];
        return a[0] > b[0];
    });
    
    vector<int> v;
    for (int i = row_begin-1; i < row_end; ++i){
        
        int sum = 0;
        for (int &n : data[i]){
            sum += n%(i+1);
        }
        v.push_back(sum);
    }
    
    int start = v[0];
    for (int i = 1; i < v.size(); ++i)
        start ^= v[i];
    return start;
}