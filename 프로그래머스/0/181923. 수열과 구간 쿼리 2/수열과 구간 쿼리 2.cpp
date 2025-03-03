#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    int mx = *max_element(arr.begin(),arr.end()) + 1;
    for (vector<int> &v : queries){
        int mn = mx;
        bool IsFind = false;
        for (int i = v[0]; i <= v[1]; ++i){
            if(arr[i] > v[2] && arr[i] < mn){
                mn = arr[i];
                IsFind = true;
            }
        }
        if(!IsFind)
            answer.push_back(-1);
        else
            answer.push_back(mn);
    }
    return answer;
}