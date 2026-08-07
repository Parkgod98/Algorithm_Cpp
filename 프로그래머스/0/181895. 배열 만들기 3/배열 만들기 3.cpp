#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> intervals) {
    vector<int> answer;
    
    for (int i = 0; i < 2; ++i){
        int s = intervals[i][0];
        int e = intervals[i][1];
        
        for (s; s <= e; ++s){
            answer.push_back(arr[s]);
        }
    }
    return answer;
}