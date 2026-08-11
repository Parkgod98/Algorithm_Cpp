#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    for(vector<int> &v : queries){
        int s = v[0];
        int e = v[1];
        
        for (s; s <= e; ++s){
            arr[s]++;
        }
    }
    return arr;
}