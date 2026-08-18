#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int s = -1;
    int e = -1;
    for (int i = 0; i < arr.size(); ++i){
        if(s == -1 && arr[i] == 2)
            s = i;
        if(s!= -1 && arr[i] == 2){
            e = i;
        }
    }
    
    if(s == -1)
        answer.push_back(-1);
    else{
        for (s; s <= e; ++s)
            answer.push_back(arr[s]);
    }
    return answer;
}