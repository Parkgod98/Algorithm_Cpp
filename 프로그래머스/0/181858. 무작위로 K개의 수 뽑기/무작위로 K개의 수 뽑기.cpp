#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    map<int,bool> mp;
    for (int i = 0; i < arr.size(); ++i){
        if(!mp[arr[i]]){
            mp[arr[i]] = true;
            if(answer.size() < k)
                answer.push_back(arr[i]);
            else
                break;
        }
    }
    int size = answer.size();
    for (int i = 0; i < k-size; ++i){
        answer.push_back(-1);
    }
    return answer;
}