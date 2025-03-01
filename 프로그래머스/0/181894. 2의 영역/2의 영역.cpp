#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int s,e;
    s = 0;
    e = arr.size();
    for (int i = 0; i < arr.size(); ++i){
        if (arr[i] == 2){
            s = i;
            break;
        }
    }
    for (int i = e -1; i >=0; --i){
        if (arr[i] == 2){
            e = i;
            break;
        }
    }
    if (e!=arr.size()){
        for (int i = s; i <=e; ++i)
            answer.push_back(arr[i]);
    }
    else{
        answer.push_back(-1);
    }
    return answer;
}