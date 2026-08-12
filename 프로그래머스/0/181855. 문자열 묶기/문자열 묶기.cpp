#include <string>
#include <vector>

using namespace std;

int solution(vector<string> strArr) {
    int answer = 0;
    
    int arr[1000001] = {0};
    for (string &s : strArr){
        arr[s.size()]++;
    }
    int mx = 0;
    for (int i = 0; i < 1000001; ++i){
        if(arr[i] > mx){
            mx = arr[i];
        }
    }
    return mx;
}