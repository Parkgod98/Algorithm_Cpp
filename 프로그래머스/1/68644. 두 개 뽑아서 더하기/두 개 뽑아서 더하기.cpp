#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    int arr[201] = {0};
    int sz = numbers.size();
    
    for (int i = 0; i < sz; ++i){
        for (int j = i + 1; j < sz; ++j){
            arr[numbers[i] + numbers[j]] = 1;
        }
    }
    
    vector<int> ans;
    for (int i = 0; i <= 200; ++i)
        if(arr[i])
            ans.push_back(i);
    return ans;
}   