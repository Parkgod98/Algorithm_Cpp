#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    vector<int> answer;
    
    int visited[1001] = {0};
    for (int &k : delete_list)
        visited[k] = 1;
    
    for (int &n : arr)
        if(!visited[n])
            answer.push_back(n);
    return answer;
}