#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> ans;
    int visited[100001] = {0};
    
    for (int &n : arr){
        if(!visited[n]){
            ans.push_back(n);
            visited[n] = 1;
            if(ans.size() == k)
                break;
        }
    }
    
    while(ans.size() < k)
        ans.push_back(-1);
    return ans;
}