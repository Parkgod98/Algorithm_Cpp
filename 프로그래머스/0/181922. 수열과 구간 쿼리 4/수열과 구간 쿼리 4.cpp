#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    for (vector<int> &v : queries){
        int s = v[0];
        int e = v[1];
        int k = v[2];
        
        for (s; s <=e; ++s){
            if(s%k == 0)
                arr[s]++;
        }
    }
    return arr;
}